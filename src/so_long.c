/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:07:09 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 10:36:44 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_pic	pics;
	int		width;
	int		height;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_mapchecker(&data, argv[1]);
	data.pics = &pics;
	pics.hei = &width;
	pics.wid = &height;
	return (0);
}

	/*
	
	x = mlx_init();
	xwin = mlx_new_window(x, 32*7, 32*7, "The Last Space Bender");
	
	while(i < 7 )
	{
	 	while(y < 7)
		{
			mlx_put_image_to_window(x, xwin, spc, i*32, y*32);
			y++;
		}
		y= 0 ;
		i++;
	}
	i =0;
	y=0;
	while(i<7)
	{
		mlx_put_image_to_window(x, xwin, wall, i*32, y*32);
		i++;
	}
	mlx_put_image_to_window(x, xwin, craft, 2*32, 0*32);
	mlx_put_image_to_window(x, xwin, power, 4*32, 0*32);
	mlx_put_image_to_window(x, xwin, portal, 6*32, 6*32);
	mlx_loop(x);
	
} */