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

char *find_next_line(char *str)
{
	int i;
	char *line;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (line = ft_strsub(str, 0, i));
}


int	get_next_line(const int fd, char **line)
{
    int ret;
    char buf[BUFF_SIZE +1];
	char tmp[4096];
	int i;

	i = 0;
	ft_bzero(tmp, 4069);
    if (fd == -1)
    {
        write(2, "Error", 6);
        return (1);
    }
    while((ret = read(fd, buf, BUFF_SIZE)) && *buf != '\n')
	{
		tmp[i] = *buf;
		i++;
    	buf[ret] = '\0';
	}
	tmp[i] = '\0';
	*line = find_next_line(tmp);
    printf("%s", buf);

    return (0);
}
