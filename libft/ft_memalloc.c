/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:16:23 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/15 17:24:48 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*zone;
	size_t	i;

	i = 0;
	if (!(zone = (char*)malloc(size)))
		return (NULL);
	while (i < size)
		zone[i++] = 0;
	return (zone);
}
