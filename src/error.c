/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:44:09 by etorun            #+#    #+#             */
/*   Updated: 2025/03/07 20:35:59 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include "so_long.h"

void	ft_error(char *message)
{
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit (1);
}

void	ft_errorf(char *message, t_data *data)
{
	int	height;

	height = data->m_h;
	while (height--)
		free(data->map[height]);
	free(data->map);
	write(1, message, ft_strlen(message));
	write(1, "\n", 1);
	exit (1);
}

void ft_free(t_data *data)
{
	int	height;

	height = data->m_h;
	while (height--)
		free(data->map[height]);
	free(data->map);
}