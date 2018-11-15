/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:02:27 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 11:28:57 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}
