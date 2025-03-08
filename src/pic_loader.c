/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:04:43 by etorun            #+#    #+#             */
/*   Updated: 2025/03/07 22:30:47 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void ft_pic_free(t_data *data)
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