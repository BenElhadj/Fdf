/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 03:53:05 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 03:13:09 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_error(int n)
{
	if (n == 1)
		ft_putendl_fd("usage: ./fdf <map>", 2);
	if (n == 2)
		ft_putendl_fd("error: something is wrong with the file", 2);
	if (n == 3)
		ft_putendl_fd("error: bad size of the file", 2);
	if (n == 4)
		ft_putendl_fd("error: bad character in the file", 2);
	return (-1);
}

/*
** Print instructions in the terminal
*/

static void	ft_info(void)
{
	ft_putendl(CMD);
	ft_putendl(ISO);
	ft_putendl(ZOOM);
	ft_putendl(MOVE);
	ft_putendl(COLOR);
	ft_putendl(PROJ);
	ft_putendl(REINIT);
}

int			main(int argc, char **argv)
{
	t_env	*e;
	int		fd;

	if (!(e = (t_env*)ft_memalloc(sizeof(t_env))))
		return (0);
	if (argc != 2)
		return (ft_error(1) == -1 ? -1 : 0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_error(2) == -1 ? -1 : 0);
	e = ft_init_all(e);
	if (ft_read_file(fd, e) == -1)
		return (ft_error(3) == -1 ? -1 : 0);
	if (!(ft_create_int_tab(e->lst, e)))
		return (ft_error(4) == -1 ? -1 : 0);
	ft_free_map(e);
	ft_info();
	ft_create_win(e);
	if ((close(fd)) == -1)
		return (ft_error(2) == -1 ? -1 : 0);
	return (0);
}
