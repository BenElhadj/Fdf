/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:37:57 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/25 11:38:30 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		str = ft_strncpy(str, &s[start], len);
		str[len] = '\0';
	}
	return (str);
}
