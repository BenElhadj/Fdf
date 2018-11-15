/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:49:44 by bhamdi            #+#    #+#             */
/*   Updated: 2017/01/25 11:50:18 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		nb_words(char const *s, char c)
{
	if (!*s)
		return (0);
	if ((*(s + 1) == c || *(s + 1) == '\0') && *s != c)
		return (1 + nb_words(s + 1, c));
	return (nb_words(s + 1, c));
}

static const char	*next_word(char **tab, size_t i, char const *s, char c)
{
	char	*str;
	size_t	len;
	size_t	j;

	while (*s == c)
		s++;
	str = (char*)s;
	while (*str && *str != c)
		str++;
	len = str - s;
	tab[i] = (char*)malloc(sizeof(*str) * (len + 1));
	j = 0;
	while (*s && *s != c)
		tab[i][j++] = *(s++);
	tab[i][j] = '\0';
	return (s);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	words;
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	words = nb_words(s, c);
	tab = (char**)malloc(sizeof(*tab) * (words + 1));
	if (tab)
	{
		i = 0;
		while (i < words)
		{
			s = next_word(tab, i, s, c);
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}
