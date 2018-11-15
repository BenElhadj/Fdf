/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 05:03:02 by bhamdi            #+#    #+#             */
/*   Updated: 2016/12/28 13:54:16 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	char	car;
	size_t	i;

	ptr = (char*)s;
	car = (char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == car)
			return ((char*)ptr + i);
		i++;
	}
	return (0);
}
