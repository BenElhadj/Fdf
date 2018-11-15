/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 05:53:15 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/28 17:18:44 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int n;
	int len;

	i = 0;
	n = 0;
	len = 0;
	while (s2[len] != '\0')
		len++;
	if (len == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[n] == s1[i + n])
		{
			if (n == len - 1)
				return ((char *)s1 + i);
			n++;
		}
		n = 0;
		i++;
	}
	return (0);
}
