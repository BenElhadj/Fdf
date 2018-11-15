/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 04:40:42 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:31:16 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_node(void *content, size_t size)
{
	ft_memdel(&content);
	size = 0;
}

void	ft_free_map(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->file.nb_y)
		free(e->file.map[i]);
	free(e->file.map);
	e->file.map = NULL;
}

void	ft_tabdel(char **tab)
{
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}
