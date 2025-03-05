/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:01:33 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 21:20:26 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

void	ft_chk_ext(char *mapname)
{
	size_t	len;

	len = ft_strlen(mapname);
	if (ft_strncmp(".ber", mapname + len - 4, 4))
		ft_error("Hatalı dosya uzantısı!!");
	else if (len < 5 || *(mapname + len - 5) == '/')
		ft_error("Hatalı dosya adı!!");
	else
		return ;
}

void	ft_chk_items(t_data *data, char chr)
{
	static int	e;
	static int	c;
	static int	p;

	if (chr == 'E')
		e++;
	else if (chr == 'C')
		c++;
	else if (chr == 'P')
		p++;
	else if (chr == '\0')
	{
		if (p != 1)
			ft_errorf("Haritada formatında 'P' sayısı hatalı!!!", data);
		if (e != 1)
			ft_errorf("Haritada formatında 'E' sayısı hatalı!!!", data);
		if (c < 1)
			ft_errorf("Haritada formatında 'C' sayısı hatalı!!!", data);
		data->powers = c;
		data->is_closed = 0;
	}
}

void	ft_chk_req(t_data *data, size_t row, size_t column)
{
	while (row-- >= 1)
	{
		while (column-- >= 1)
		{
			if (data->map[row][column] == 'E')
				ft_chk_items(data, 'E');
			else if (data->map[row][column] == 'P')
			{
				ft_chk_items(data, 'P');
				data->cur_x = column + 1;
				data->cur_y = row + 1;
			}
			else if (data->map[row][column] == 'C')
				ft_chk_items(data, 'C');
			else if (data->map[row][column] == '1')
				continue ;
			else if (data->map[row][column] == '0')
				continue ;
			else
				ft_errorf("Haritada formatına uygun olmayan karekter!!!", data);
		}
		column = data->m_w;
	}
	ft_chk_items(data, '\0');
}

void	ft_mapchecker(t_data *data, char *mapname)
{
	ft_chk_ext(mapname);
	ft_maphandler(data, mapname);
	ft_map_loader(data, mapname);
	ft_chk_dim(data);
	ft_chk_walls(data, data->m_w, data->m_h);
	ft_chk_req(data, data->m_h, data->m_w);
	ft_mapreach(data, data->m_h, data->powers);
}

void	ft_mapreach(t_data *data, int row, int powers)
{
	char	**temp;

	temp = malloc (sizeof(char *) * row);
	while (row-- > 0)
	{
		temp[row] = malloc(sizeof(char) * data->m_w);
		ft_memcpy (temp[row], data->map[row], data->m_w);
	}
	ft_chk_reach(data, temp, data->cur_y - 1, data->cur_x - 1);
	row = data->m_h;
	while (row-- > 0)
		free(temp[row]);
	free (temp);
	if (data->powers != 0 || data->is_closed == 0)
		ft_errorf("Exit veya powerlar ulaşılabilir değil", data);
	data->powers = powers;
}
