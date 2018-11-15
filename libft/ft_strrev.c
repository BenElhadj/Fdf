/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 03:50:47 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 04:37:55 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	sw;

	i = 0;
	len = 0;
	while (str[i])
		i++;
	i = i - 1;
	while (len < i)
	{
		sw = str[i];
		str[i] = str[len];
		str[len] = sw;
		i--;
		len++;
	}
	return (str);
}
