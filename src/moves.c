/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:46:09 by etorun            #+#    #+#             */
/*   Updated: 2025/03/09 01:26:36 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../ft_printf/ft_printf.h"

void	ft_move_down(t_data *data)
{
	if (data->map[data->cur_y][data->cur_x - 1] == 'C')
		data->powers--;
	if (data->map[data->cur_y][data->cur_x - 1] != '1')
	{
		if (data->map[data->cur_y][data->cur_x - 1] == 'E' && data->powers != 0)
			return ;
		else
		{
			data->moves++;
			ft_printf("Moves = %d\n", data->moves);
			if (data->map[data->cur_y][data->cur_x - 1]
				== 'E' && data->powers == 0)
				ft_close_win(data);
			data->map[data->cur_y - 1][data->cur_x - 1] = '0';
			data->pics->craft = data->pics->down;
			data->map[data->cur_y][data->cur_x - 1] = 'P';
			data->cur_y = data->cur_y + 1;
		}
	}
}

void	ft_move_up(t_data *data)
{
	if (data->map[data->cur_y - 2][data->cur_x - 1] == 'C')
		data->powers--;
	if (data->map[data->cur_y - 2][data->cur_x - 1] != '1')
	{
		if (data->map[data->cur_y -2][data->cur_x - 1]
			== 'E' && data->powers != 0)
			return ;
		else
		{
			data->moves++;
			ft_printf("Moves = %d\n", data->moves);
			if (data->map[data->cur_y - 2][data->cur_x - 1]
				== 'E' && data->powers == 0)
				ft_close_win(data);
			data->map[data->cur_y - 1][data->cur_x - 1] = '0';
			data->pics->craft = data->pics->up;
			data->map[data->cur_y - 2][data->cur_x - 1] = 'P';
			data->cur_y = data->cur_y - 1;
		}
	}
}

void	ft_move_left(t_data *data)
{
	if (data->map[data->cur_y - 1][data->cur_x - 2] == 'C')
		data->powers--;
	if (data->map[data->cur_y - 1][data->cur_x - 2] != '1')
	{
		if (data->map[data->cur_y - 1][data->cur_x - 2]
			== 'E' && data->powers != 0)
			return ;
		else
		{
			data->moves++;
			ft_printf("Moves = %d\n", data->moves);
			if (data->map[data->cur_y - 1][data->cur_x - 2]
				== 'E' && data->powers == 0)
				ft_close_win(data);
			data->map[data->cur_y - 1][data->cur_x - 1] = '0';
			data->pics->craft = data->pics->left;
			data->map[data->cur_y - 1][data->cur_x - 2] = 'P';
			data->cur_x = data->cur_x - 1;
		}
	}
}

void	ft_move_right(t_data *data)
{
	if (data->map[data->cur_y - 1][data->cur_x] == 'C')
		data->powers--;
	if (data->map[data->cur_y - 1][data->cur_x] != '1')
	{
		if (data->map[data->cur_y -1][data->cur_x] == 'E' && data->powers != 0)
			return ;
		else
		{
			data->moves++;
			ft_printf("Moves = %d\n", data->moves);
			if (data->map[data->cur_y - 1][data->cur_x]
				== 'E' && data->powers == 0)
				ft_close_win(data);
			data->map[data->cur_y - 1][data->cur_x - 1] = '0';
			data->pics->craft = data->pics->right;
			data->map[data->cur_y - 1][data->cur_x] = 'P';
			data->cur_x = data->cur_x + 1;
		}
	}
}
