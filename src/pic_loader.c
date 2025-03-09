/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:04:43 by etorun            #+#    #+#             */
/*   Updated: 2025/03/09 01:22:55 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <unistd.h>

int	ft_pic_exist(void)
{
	char	*textures[9];
	int		i;
	int		fd;

	i = 0;
	textures[0] = "textures/spc.xpm";
	textures[1] = "textures/wall.xpm";
	textures[2] = "textures/up.xpm";
	textures[3] = "textures/down.xpm";
	textures[4] = "textures/left.xpm";
	textures[5] = "textures/right.xpm";
	textures[6] = "textures/portal.xpm";
	textures[7] = "textures/closed.xpm";
	textures[8] = "textures/power.xpm";
	while (i <= 8)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd == -1)
			return (0);
		close(fd);
		i++;
	}
	return (1);
}

void	ft_pic_loader(void *x, t_pic *p)
{
	p->spc = mlx_xpm_file_to_image(x, "textures/spc.xpm", p->wid, p->hei);
	p->wall = mlx_xpm_file_to_image(x, "textures/wall.xpm", p->wid, p->hei);
	p->up = mlx_xpm_file_to_image(x, "textures/up.xpm", p->wid, p->hei);
	p->down = mlx_xpm_file_to_image(x, "textures/down.xpm", p->wid, p->hei);
	p->left = mlx_xpm_file_to_image(x, "textures/left.xpm", p->wid, p->hei);
	p->right = mlx_xpm_file_to_image(x, "textures/right.xpm", p->wid, p->hei);
	p->por = mlx_xpm_file_to_image(x, "textures/portal.xpm", p->wid, p->hei);
	p->c_por = mlx_xpm_file_to_image(x, "textures/closed.xpm", p->wid, p->hei);
	p->power = mlx_xpm_file_to_image(x, "textures/power.xpm", p->wid, p->hei);
	p->craft = p->right;
}

void	ft_pic_free(t_data *data)
{
	mlx_destroy_image(data->mx, data->pics->spc);
	mlx_destroy_image(data->mx, data->pics->wall);
	mlx_destroy_image(data->mx, data->pics->up);
	mlx_destroy_image(data->mx, data->pics->down);
	mlx_destroy_image(data->mx, data->pics->left);
	mlx_destroy_image(data->mx, data->pics->right);
	mlx_destroy_image(data->mx, data->pics->por);
	mlx_destroy_image(data->mx, data->pics->c_por);
	mlx_destroy_image(data->mx, data->pics->power);
}
