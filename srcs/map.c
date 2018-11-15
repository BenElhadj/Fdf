/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 05:04:14 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:36:52 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso(t_env *e, int x, int y)
{
	t_file	f;
	float	change_z;

	f = e->file;
	change_z = f.map[y][x].z * f.depth;
	if (e->proj == 1)
	{
		f.map[y][x].x = e->margin_l + (x - y) * (f.space / 2);
		f.map[y][x].y = e->margin_t + (x + y) * (f.space / 2) - change_z;
	}
	if (e->proj == 0)
	{
		f.map[y][x].x = e->margin_l + (x * f.space);
		f.map[y][x].y = e->margin_t + (y * f.space) - change_z;
	}
}

t_map			**ft_create_int_tab(t_list *lst, t_env *e)
{
	int			x;
	int			y;
	t_list		**start;

	start = &lst;
	e->file.map = (t_map**)ft_memalloc(sizeof(t_map*) * e->file.nb_y + 1);
	y = -1;
	while (++y < e->file.nb_y)
	{
		e->file.split = ft_strsplit((char*)lst->content, ' ');
		e->file.map[y] = (t_map*)ft_memalloc(sizeof(t_map) * e->file.nb_x);
		x = -1;
		while (++x < e->file.nb_x)
		{
			e->file.map[y][x].z = ft_atoi(e->file.split[x]);
			ft_iso(e, x, y);
			ft_strdel(&e->file.split[x]);
		}
		ft_tabdel(e->file.split);
		lst = lst->next;
	}
	ft_lstdel(start, ft_free_node);
	e->file.map[e->file.nb_y] = NULL;
	return (e->file.map);
}
