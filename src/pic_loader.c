/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:04:43 by etorun            #+#    #+#             */
/*   Updated: 2025/03/04 12:50:28 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pic_loader(void *x, t_pic *p)
{
	p->spc = mlx_xpm_file_to_image(x, "assets/spc.xpm", p->wid, p->hei);
	p->wall = mlx_xpm_file_to_image(x, "assets/wall.xpm", p->wid, p->hei);
	p->up = mlx_xpm_file_to_image(x, "assets/up.xpm", p->wid, p->hei);
	p->down = mlx_xpm_file_to_image(x, "assets/down.xpm", p->wid, p->hei);
	p->left = mlx_xpm_file_to_image(x, "assets/left.xpm", p->wid, p->hei);
	p->right = mlx_xpm_file_to_image(x, "assets/right.xpm", p->wid, p->hei);
	p->portal = mlx_xpm_file_to_image(x, "assets/portal.xpm", p->wid, p->hei);
	p->closed = mlx_xpm_file_to_image(x, "assets/closed.xpm", p->wid, p->hei);
	p->power = mlx_xpm_file_to_image(x, "assets/power.xpm", p->wid, p->hei);
}
