/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:52:06 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/31 10:59:07 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int i;

	i = n;
	if (i < 0)
	{
		i = -i;
		ft_putchar_fd('-', fd);
	}
	if (i >= 0 && i <= 9)
		ft_putchar_fd(i + 48, fd);
	else
	{
		ft_putnbr_fd((int)(i / 10), fd);
		ft_putchar_fd(i % 10 + 48, fd);
	}
}
