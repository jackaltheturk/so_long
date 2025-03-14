/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 06:56:33 by etorun            #+#    #+#             */
/*   Updated: 2025/03/09 22:25:02 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>

typedef struct s_pic
{
	void	*craft;
	void	*c_por;
	void	*por;
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
	void	*mx;
	void	*wi;
	t_pic	*pics;
	char	**map;
	int		powers;
	int		is_closed;
	int		cur_x;
	int		cur_y;
	size_t	m_w;
	size_t	m_h;
	int		moves;
}	t_data;

char	*get_next_line(int fd);
void	ft_error(char *message);
void	ft_errorf(char *message, t_data *data);
void	ft_chk_reach(t_data *data, char **temp, int x, int y);
void	ft_chk_dim(t_data *data);
void	ft_chk_walls(t_data *data, size_t width, size_t height);
void	ft_map_loader(t_data *data, char *mapname);
void	ft_maphandler(t_data *data, char *mapname);
void	ft_mapchecker(t_data *data, char *mapname);
void	ft_action(t_data *data);
int		ft_close_win(t_data *data);
void	ft_pic_loader(void *x, t_pic *p);
void	ft_pic_free(t_data *data);
void	ft_free(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_up(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
int		ft_pic_exist(void);
#endif