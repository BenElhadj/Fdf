/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 21:16:51 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/29 23:09:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
