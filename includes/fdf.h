/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:52:09 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:13:48 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define ESC 53
# define TAB 48
# define ENT 36
# define PLUS 35
# define MIN 37
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define FRONT 69
# define BACK 78
# define R 15
# define G 5
# define B 11
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<2)

# define CMD "COMMANDS :"
# define ISO "P/L : increase/lower the depth"
# define ZOOM "Left click or + : zoom in\nRight click or - : zoom out"
# define MOVE "Arrow up/down/left/right : move the map"
# define COLOR "R/G/B : change the color"
# define PROJ "Tab : change the projection of the map"
# define REINIT "Enter : reinitialise the map"

typedef struct	s_color
{
	int			tmp_r;
	int			tmp_g;
	int			tmp_b;
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_map
{
	int			x;
	int			y;
	int			z;
}				t_map;

typedef struct	s_file
{
	t_map		**map;
	char		**split;
	int			nb_x;
	int			nb_y;
	int			space;
	int			depth;
}				t_file;

typedef struct	s_point
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err1;
	int			err2;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	int			margin_l;
	int			margin_t;
	int			proj;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	t_file		file;
	t_list		*lst;
	t_point		point;
	t_color		color;
}				t_env;

t_env			*ft_init_all(t_env *e);
int				ft_read_file(int fd, t_env *e);
t_map			**ft_create_int_tab(t_list *lst, t_env *e);
void			ft_draw_grid(t_env *e);
int				ft_create_win(t_env *e);
int				ft_expose_hook(t_env *e);

void			ft_change_proj(t_env *e);
void			ft_change_depth(int key, t_env *e);
void			ft_zoom(int key, t_env *e);
void			ft_move(int key, t_env *e);
void			ft_reinit(t_env *e);
void			ft_change_color(int key, t_env *e);

void			ft_tabdel(char **tab);
void			ft_free_node(void *content, size_t size);
void			ft_free_map(t_env *e);

#endif
