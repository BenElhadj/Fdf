/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 04:51:51 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:32:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_color(t_env *e)
{
	e->color.tmp_r = 0;
	e->color.tmp_g = 0;
	e->color.tmp_b = 0;
	e->color.r = 255;
	e->color.g = 255;
	e->color.b = 255;
}

static void		ft_init_point(t_env *e)
{
	e->point.dx = 0;
	e->point.dy = 0;
	e->point.sx = 0;
	e->point.sy = 0;
	e->point.err1 = 0;
	e->point.err2 = 0;
}

static void		ft_init_file(t_env *e)
{
	e->file.nb_x = 0;
	e->file.nb_y = 0;
	e->file.map = NULL;
	e->file.space = 30;
	e->file.split = NULL;
	e->file.depth = 2;
}

t_env			*ft_init_all(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->win_x = 1300;
	e->win_y = 700;
	e->margin_l = 400;
	e->margin_t = 100;
	e->proj = 1;
	e->img = NULL;
	e->data = NULL;
	ft_init_point(e);
	ft_init_file(e);
	ft_init_color(e);
	return (e);
}
