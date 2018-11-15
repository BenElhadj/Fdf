/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 03:18:10 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/28 16:32:19 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	size;
	char	*ret;

	size = 0;
	i = 0;
	while (src[size] != '\0')
		size++;
	if (src != 0)
	{
		if (!(ret = (char*)malloc(sizeof(*ret) * size + 1)))
			return (NULL);
		while (i < size)
		{
			ret[i] = src[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
