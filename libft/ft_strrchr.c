/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:13:57 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/08 20:44:59 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*str;
	size_t	i;

	c2 = (char)c;
	i = 1;
	str = (char*)s;
	while (str[i])
		i++;
	while (str[i] != c2 && i >= 1)
		i--;
	if (str[i] == c2)
		return (&str[i]);
	else
		return (0);
}
