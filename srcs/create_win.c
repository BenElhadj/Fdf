/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 04:27:07 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 05:16:40 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Create instructions for the window
*/

static void		ft_instruction(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 0, 0x00FFFFFF, CMD);
	mlx_string_put(e->mlx, e->win, 10, 20, 0x00FFFFFF, ISO);
	mlx_string_put(e->mlx, e->win, 10, 40, 0x00FFFFFF, ZOOM);
	mlx_string_put(e->mlx, e->win, 10, 60, 0x00FFFFFF, MOVE);
	mlx_string_put(e->mlx, e->win, 10, 80, 0x00FFFFFF, COLOR);
	mlx_string_put(e->mlx, e->win, 10, 100, 0x00FFFFFF, PROJ);
	mlx_string_put(e->mlx, e->win, 10, 120, 0x00FFFFFF, REINIT);
}

/*
** Zoom/dezoom with mouse
*/

static int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	ft_putstr("Mouse ");
	ft_putnbr(button);
	ft_putstr(": x: ");
	ft_putnbr(x);
	ft_putstr(" | y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	if (button == 1)
		e->file.space += 5;
	else if (button == 2 && e->file.space > 5)
		e->file.space -= 5;
	ft_expose_hook(e);
	return (0);
}

/*
** Use keys of keyboard for navigate, TAB for change projection
*/

static int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	else if (keycode == TAB)
		ft_change_proj(e);
	else if (keycode == PLUS || keycode == MIN)
		ft_change_depth(keycode, e);
	else if (keycode == FRONT || keycode == BACK)
		ft_zoom(keycode, e);
	else if (keycode == UP || keycode == DOWN
			|| keycode == LEFT || keycode == RIGHT)
		ft_move(keycode, e);
	else if (keycode == ENT)
		ft_reinit(e);
	else if (keycode == R || keycode == G || keycode == B)
		ft_change_color(keycode, e);
	ft_expose_hook(e);
	return (0);
}

/*
** Create and print image, print instructions
*/

int				ft_expose_hook(t_env *e)
{
	t_map	**tmp;
	int		i;

	e->img = mlx_new_image(e->mlx, e->win_x, e->win_y);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	tmp = ft_create_int_tab(e->lst, e);
	i = -1;
	ft_draw_grid(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	ft_instruction(e);
	mlx_destroy_image(e->mlx, e->img);
	while (tmp[++i] != NULL)
		free(tmp[i]);
	free(tmp);
	return (0);
}

/*
** Init MLX, create window, set event for mouse/keyboard
*/

int				ft_create_win(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		ft_putendl_fd("Error minilibx init", 2);
		return (-1);
	}
	e->win = mlx_new_window(e->mlx, e->win_x, e->win_y, "fdf");
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, ft_key_hook, e);
	mlx_mouse_hook(e->win, ft_mouse_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
