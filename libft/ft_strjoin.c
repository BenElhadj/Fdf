/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:32:32 by bhamdi            #+#    #+#             */
/*   Updated: 2017/02/27 01:31:28 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = s1 ? ft_strlen(s1) : 0;
	len_s2 = s2 ? ft_strlen(s2) : 0;
	str = (char *)malloc(sizeof(*str) * (len_s1 + len_s2 + 1));
	if (s1)
		ft_strcpy(str, s1);
	if (s2)
		ft_strcpy(str + len_s1, s2);
	str[len_s1 + len_s2] = '\0';
	return (str);
}
