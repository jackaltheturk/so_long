/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:07:09 by etorun            #+#    #+#             */
/*   Updated: 2025/03/09 21:13:14 by etorun           ###   ########.fr       */
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
	if (!ft_pic_exist())
	{
		write(1, "Error\n", 6);
		write(1, "Texture(s) couldn't be found!!!\n", 33);
		return (1);
	}
	ft_mapchecker(&data, argv[1]);
	data.pics = &pics;
	pics.hei = &width;
	pics.wid = &height;
	ft_action(&data);
	return (0);
}
