/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 16:31:53 by bhamdi            #+#    #+#             */
/*   Updated: 2018/03/31 03:59:20 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char		*get_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	if (src == 0)
	{
		dest[i] = '\0';
		return (dest);
	}
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*get_strncat(char *dest, const char *src, size_t nb)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (dest[size])
		size++;
	while (src[i] && i < nb)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

static int		get_line(char *buf, char **line)
{
	char	*temp;
	int		i;
	int		k;

	i = -1;
	k = 0;
	while (buf[++i])
		if (buf[i] == '\n')
			break ;
	if (!(temp = (char *)malloc(sizeof(char) * (get_strlen(*line) + i + 1))))
		return (0);
	get_strcpy(temp, *line);
	free(*line);
	get_strncat(temp, buf, i);
	buf[i] == '\n' ? k = 1 : 0;
	if (k != 1)
		buf[0] = '\0';
	else
		get_strcpy(buf, &(buf[i + 1]));
	*line = temp;
	return (k);
}

int				get_next_line(const int fd, char **line)
{
	static char	buf[NB_FD][BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || read(fd, &ret, 0) == -1)
		return (-1);
	*line = NULL;
	ret = 0;
	if (buf[fd][0] && get_line(buf[fd], line) == 1)
		return (1);
	while ((ret = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		buf[fd][ret] = '\0';
		if (get_line(buf[fd], line) == 1)
			return (1);
	}
	return (*line ? 1 : 0);
}
