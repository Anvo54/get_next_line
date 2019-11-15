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

int				find_next_line(const char **str, char ***l_str)
{
	char		*line;
	int			i;
	int			result;

	i = 0;
	result = 0;
	if ((*str)[0] == '\0')
	{
		**l_str = "";
		return (1);
	}
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
	{
		if ((*str)[i] == '\0')
			result = 1;
		i++;
	}
	**l_str = ft_strsub(*str, 0, i);
	while ((i--) >= 0)
		(*str)++;
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	const char	*str[FD_SIZE];
	char		*tmp;

	if (fd > FD_SIZE && !line)
	{
		write(2, "Error", 6);
		return (-1);
	}
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
