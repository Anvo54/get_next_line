/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:32 by avornane          #+#    #+#             */
/*   Updated: 2019/11/08 15:01:40 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h> // remove

char *find_next_line(const char **str)
{
	char *line;
	int i;

	i = 0;
	while((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	line = ft_strsub(*str, 0, i);
	while((i--) >= 0)
		(*str)++;
	return(line);
}


int	get_next_line(const int fd, char **line)
{
	int ret;
	char buf[BUFF_SIZE +1];
	const char *str[FD_SIZE];
	char *tmp;

	if (fd > FD_SIZE)
	{
		write(2, "Error", 6);
		return (1);
	}
	while((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[0] == NULL)
		{
			str[0] = ft_strdup(buf);
		}
		else
		{
			tmp = ft_strjoin(str[0], buf);
			free(str[0]);
			str[0] = tmp;
		}
	}
	if (str[0][0] != '\0')
		*line = find_next_line(&str[0]);
	return (0);
}
