/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:21:06 by etorun            #+#    #+#             */
/*   Updated: 2025/03/08 18:19:58 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../mlx.h"
#include "so_long.h"
#include <stdio.h>

void	ft_pic_putter(void *mx, void *wi, t_data *data, t_pic *pic)
{
	int	h;
	int	w;

	h = data->m_h;
	w = data->m_w;
	while (--h >= 0)
	{
		while (--w >= 0)
		{
			if (data->map[h][w] == 'E' && data->powers == 0)
				mlx_put_image_to_window(mx, wi, pic->por, w * 32, h * 32);
			else if (data->map[h][w] == 'E' && data->powers != 0)
				mlx_put_image_to_window(mx, wi, pic->c_por, w * 32, h * 32);
			else if (data->map[h][w] == 'P')
				mlx_put_image_to_window(mx, wi, pic->craft, w * 32, h * 32);
			else if (data->map[h][w] == 'C')
				mlx_put_image_to_window(mx, wi, pic->power, w * 32, h * 32);
			else if (data->map[h][w] == '1')
				mlx_put_image_to_window(mx, wi, pic->wall, w * 32, h * 32);
			else if (data->map[h][w] == '0')
				mlx_put_image_to_window(mx, wi, pic->spc, w * 32, h * 32);
		}
		w = data->m_w;
	}
}

int key_hook(int keycode, t_data *data) 
{
	if (keycode == 65307) // Esc key
        ft_close_win(data);
    if (keycode == 65361) // Left arrow key
        ft_move_left(data);
    if (keycode == 65362) // Up arrow key
        ft_move_up(data);
    if (keycode == 65363) // Right arrow key
        ft_move_right(data);
    if (keycode == 65364) // Down arrow key
        ft_move_down(data);
    mlx_clear_window(data->mx, data->wi);
    ft_pic_putter(data->mx, data->wi, data, data->pics);
    return (0);
}

int	ft_close_win(t_data *data)
{
	mlx_destroy_window(data->mx, data->wi);
	ft_pic_free(data);
	mlx_destroy_display(data->mx);
	ft_free(data);
	free(data->mx);
	exit(0);
}


void	ft_action(t_data *data)
{
	data->moves = 0;
	data->mx = mlx_init();
	if (!data->mx)
		ft_errorf("Couldn't establish connection", data);
	data->wi = mlx_new_window(data->mx, data->m_w * 32, data->m_h * 32, "so_long");
	if (!data->wi)
		ft_errorf("Couldn't start window", data);
	ft_pic_loader(data->mx, data->pics);
	ft_pic_putter(data->mx,data->wi, data, data->pics);
	mlx_key_hook(data->wi, key_hook, data);
	mlx_hook(data->wi, 33, 1L<<17, ft_close_win, data);
	mlx_loop(data->mx);
}
