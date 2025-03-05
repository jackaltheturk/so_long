/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:01:33 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 10:35:34 by etorun           ###   ########.fr       */
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

void	ft_mapchecker(t_data *data, char *mapname)
{
	ft_chk_ext(mapname);
	ft_maphandler(data, mapname);
	ft_map_loader(data, mapname);
	ft_chk_dim(data);
	ft_chk_walls(data, data->map_width, data->map_height);
}