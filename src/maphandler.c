/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maphandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:04:16 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 10:33:54 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

void	ft_chk_walls(t_data *data, size_t width, size_t height)
{
	size_t	w;
	size_t	h;

	w = width + 1;
	h = height + 1;
	while (--w > 0)
		if (data->map[0][w - 1] != '1')
			ft_errorf("Harita duvarları standart dışı!!!", data);
	while (w++ < width)
		if (data->map[height - 1][w - 1] != '1')
			ft_errorf("Harita duvarları standart dışı!!!", data);
	while (--h > 0)
		if (data->map[h - 1][0] != '1')
			ft_errorf("Harita duvarları standart dışı!!!", data);
	while (h++ < height)
		if (data->map[h - 1][width - 1] != '1')
			ft_errorf("Harita duvarları standart dışı!!!", data);
}

void	ft_chk_dim(t_data *data)
{
	size_t	height;
	size_t	width;
	int		flag;

	flag = 0;
	height = data->map_height;
	width = ft_strlen(data->map[0]);
	data->map_width = width - 1;
	if (width < 4 || height < 3)
		ft_errorf("Harita boyutları uygunsuz!!!", data);
	while (height-- > 0)
	{
		if (flag == 0)
		{
			if (width - 1 != ft_strlen(data->map[height]))
				ft_errorf("Harita boyutları uygunsuz!!!", data);
			flag = 1;
		}
		else
		{
			if (width != ft_strlen(data->map[height]))
				ft_errorf("Harita boyutları uygunsuz!!!", data);
		}
	}
}

void	ft_map_loader(t_data *data, char *mapname)
{
	int		fd;
	size_t	line;
	size_t	i;

	i = 0;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		ft_error("Böyle bir dosya yok!!!");
	line = data->map_height;
	while (i < line)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	ft_maphandler(t_data *data, char *mapname)
{
	int		fd;
	size_t	line;
	char	*string;

	line = 0;
	fd = open(mapname, O_RDONLY);
	if (fd == -1)
		ft_error("Böyle bir dosya yok!!!");
	string = get_next_line(fd);
	if (!string)
		ft_error("Boş dosya!!!");
	while (string)
	{
		free(string);
		string = get_next_line(fd);
		line++;
	}
	close(fd);
	data->map_height = line;
	data->map = malloc(sizeof(char *) * line);
	if (!data->map)
		ft_error("Yetersiz ram miktarı!!!");
}
