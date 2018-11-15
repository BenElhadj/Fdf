/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 04:45:04 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 04:46:40 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	ft_putstr("hello world\n");
	i = 42;
	ft_putchar('\n');
	ft_strcpy(str, "hello world\n");
	return (0);
}
