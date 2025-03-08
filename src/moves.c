/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:46:09 by etorun            #+#    #+#             */
/*   Updated: 2025/03/07 23:04:45 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_move_down(t_data *data)
{
	data->is_closed = 1;
	
}
void	ft_move_up(t_data *data)
{
	data->is_closed = 0;
}
void	ft_move_left(t_data *data)
{
	data->is_closed = 1;
}
void	ft_move_right(t_data *data)
{
	data->is_closed = 0;
}