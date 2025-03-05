/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:56:33 by etorun            #+#    #+#             */
/*   Updated: 2025/03/05 21:08:32 by etorun           ###   ########.fr       */
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
	size_t	m_w;
	size_t	m_h;
}	t_data;

char	*get_next_line(int fd);
void	ft_error(char *message);
void	ft_errorf(char *message, t_data *data);
void	ft_chk_ext(char *mapname);
void	ft_mapreach(t_data *data, int row, int powers);
void	ft_chk_reach(t_data *data, char **temp, int x, int y);
void	ft_chk_dim(t_data *data);
void	ft_chk_req(t_data *data, size_t row, size_t column);
void	ft_chk_items(t_data *data, char chr);
void	ft_chk_walls(t_data *data, size_t width, size_t height);
void	ft_map_loader(t_data *data, char *mapname);
void	ft_maphandler(t_data *data, char *mapname);
void	ft_mapchecker(t_data *data, char *mapname);
#endif