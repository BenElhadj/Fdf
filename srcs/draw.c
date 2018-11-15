/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 04:28:24 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:29:12 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Apply color regarding depth of the map
*/

static void		ft_color(t_env *e, t_map p1, t_map p2)
{
	if (p1.z == 0 && p1.z == p2.z)
	{
		e->color.r = 255;
		e->color.g = 255;
		e->color.b = 255;
	}
	else if (p1.z * e->file.depth < 0)
	{
		e->color.r = 0 + e->color.tmp_r;
		e->color.g = 55 + e->color.tmp_g;
		e->color.b = 153 + e->color.tmp_b;
	}
	else
	{
		e->color.r = 51 + e->color.tmp_r;
		e->color.g = 153 + e->color.tmp_g;
		e->color.b = 255 + e->color.tmp_b;
	}
}

/*
** Print pixel in the window
*/

static void		ft_pixel_put(t_env *e, t_map p1, t_map p2)
{
	int		i;

	if ((p1.x > 0 && p1.x < e->win_x) && (p1.y > 0 && p1.y < e->win_y))
	{
		i = (p1.y * e->sizeline) + (p1.x * e->bpp / 8);
		e->data[i] = e->color.b;
		e->data[i + 1] = e->color.g;
		e->data[i + 2] = e->color.r;
	}
	ft_color(e, p1, p2);
}

/*
** Algo of bresenham
*/

static void		ft_draw_line(t_env *e, t_map p1, t_map p2)
{
	t_point	p;

	p = e->point;
	p.dx = abs(p2.x - p1.x);
	p.dy = abs(p2.y - p1.y);
	p.sx = (p1.x < p2.x) ? 1 : -1;
	p.sy = (p1.y < p2.y) ? 1 : -1;
	p.err1 = (p.dx > p.dy ? p.dx : -p.dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		p.err2 = p.err1;
		if (p.err2 >= -p.dx)
		{
			p.err1 -= p.dy;
			p1.x += p.sx;
		}
		if (p.err2 <= p.dy)
		{
			p.err1 += p.dx;
			p1.y += p.sy;
		}
		ft_pixel_put(e, p1, p2);
	}
}

/*
** link lines for print a complete map
*/

void			ft_draw_grid(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->file.nb_y)
	{
		x = -1;
		while (++x < e->file.nb_x)
		{
			if (x < e->file.nb_x - 1)
				ft_draw_line(e, e->file.map[y][x], e->file.map[y][x + 1]);
			if (y < e->file.nb_y - 1)
				ft_draw_line(e, e->file.map[y][x], e->file.map[y + 1][x]);
		}
	}
}

/*
** Change colors with R G B keys
*/

void			ft_change_color(int key, t_env *e)
{
	if (key == R)
		e->color.tmp_r += 10;
	if (key == G)
		e->color.tmp_g += 10;
	if (key == B)
		e->color.tmp_b += 10;
}
