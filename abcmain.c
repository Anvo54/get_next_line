/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abcmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:47:19 by avornane          #+#    #+#             */
/*   Updated: 2019/11/19 12:52:26 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>


int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	ret = get_next_line(fd, &line);
	printf("ret is: %d\n", ret);
	printf("line is: %s\n", line);
	if (line)
		free(line);
	line = NULL;
	ret = 0;
	ret = get_next_line(fd, &line);
	printf("ret is: %d\n", ret);
	printf("line is: %s\n", line);
	if (line)
		free(line);
	line = NULL;
	ret = 0;
	ret = get_next_line(fd, &line);
	printf("ret is: %d\n", ret);
	printf("line is: %s\n", line);
	if (line)
		free(line);
	line = NULL;
	ret = 0;
	ret = get_next_line(fd, &line);
	printf("ret is: %d\n", ret);
	printf("line is: %s\n", line);
	if (line)
		free(line);
	line = NULL;
	ret = 0;
	return (0);
}

