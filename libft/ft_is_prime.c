/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 03:35:55 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 04:32:53 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_prime(int nb)
{
	int	prime;

	prime = 3;
	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while ((prime * prime) <= nb)
	{
		if ((nb % prime) == 0)
			return (0);
		prime = prime + 2;
	}
	return (1);
}
