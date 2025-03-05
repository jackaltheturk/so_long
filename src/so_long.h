/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:56:33 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 10:37:31 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx.h"
# include <stdlib.h>

typedef struct s_pic
{
	void	*closed;
	void	*portal;
	void	*spc;
	void	*wall;
	void	*power;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
	int		*wid;
	int		*hei;
}	t_pic;

typedef struct s_data
{
	t_pic	*pics;
	char	**map;
	int		powers;
	int		is_closed;
	int		cur_x;
	int		cur_y;
	size_t	map_width;
	size_t	map_height;
}	t_data;

char	*get_next_line(int fd);
void	ft_error(char *message);
void	ft_errorf(char *message, t_data *data);
void	ft_chk_ext(char *mapname);
void	ft_chk_dim(t_data *data);
void	ft_chk_walls(t_data *data, size_t width, size_t height);
void	ft_map_loader(t_data *data, char *mapname);
void	ft_maphandler(t_data *data, char *mapname);
void	ft_mapchecker(t_data *data, char *mapname);
#endif