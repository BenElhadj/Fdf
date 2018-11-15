/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 04:29:07 by bhamdi            #+#    #+#             */
/*   Updated: 2018/09/19 02:30:24 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;
	int		k;

	if (argc < 1)
		return (0);
	i = 1;
	k = 1;
	while (i <= argc && (fd = open(argv[i++], O_RDONLY)))
	{
		if (fd == -1)
			return (1);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("\n****************************** fin de fichier numero %d", k);
		printf("%s\n", argv[i - 1]);
		printf("BUFF_SIZE => %lu\n", BUFF_SIZE);
		k++;
		close(fd);
	}
	return (0);
}
