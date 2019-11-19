/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:58:32 by avornane          #+#    #+#             */
/*   Updated: 2019/11/19 13:21:36 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int				find_next_line(char **str, char ***l_str)
{
	int			i;

	i = 0;
	if (str[0] == NULL)
		return (-1);
	if ((*str)[0] == '\0')
	{
		str = NULL;
		ft_strdel(*l_str);
		return (0);
	}
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	**l_str = ft_strsub(*str, 0, i);
	while ((i--) >= 0)
		(*str)++;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp;

	if (fd > FD_SIZE || line == NULL || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	return (find_next_line(&str[fd], &line));
}
