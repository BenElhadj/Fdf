/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 05:37:51 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/30 04:38:58 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_lst_push_back(t_list **list, char *line)
{
	while (*list != NULL)
		list = &(*list)->next;
	if (*list == NULL)
		*list = ft_lstnew(line, ft_strlen(line) + 1);
}

static int		ft_get_size(t_env *e)
{
	int		i;
	int		flag;
	int		tmp_x;
	t_list	*tmp;

	flag = 0;
	tmp = e->lst;
	while (tmp)
	{
		e->file.split = ft_strsplit(tmp->content, ' ');
		i = -1;
		while (e->file.split[++i])
			ft_strdel(&e->file.split[i]);
		ft_tabdel(e->file.split);
		if (e->file.nb_x == 0 && flag == 0)
		{
			flag = 1;
			e->file.nb_x = i;
		}
		tmp_x = i;
		if (e->file.nb_x != tmp_x)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_check_num(char *content)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(content);
	while (++i < len)
	{
		if (((content[i] >= 'a' && content[i] <= 'z')
			|| (content[i] >= 'A' && content[i] <= 'Z'))
			&& (content[i] != 'x' && content[i] != 'f'))
			return (-1);
	}
	return (0);
}

int				ft_read_file(int fd, t_env *e)
{
	char	*line;
	t_list	**start;

	e->lst = NULL;
	start = &e->lst;
	line = NULL;
	if (get_next_line(fd, &line) < 1)
		return (-1);
	e->lst = ft_lstnew(line, ft_strlen(line) + 1);
	if ((ft_check_num(e->lst->content)) == -1)
		return (-1);
	free(line);
	line = NULL;
	e->file.nb_y++;
	while (get_next_line(fd, &line))
	{
		if ((ft_check_num(line)) == -1)
			return (-1);
		ft_lst_push_back(&e->lst, line);
		e->file.nb_y++;
		free(line);
		line = NULL;
	}
	return ((ft_get_size(e) == -1 ? -1 : 0));
}
