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
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
    int ret;
    char buf[BUFF_SIZE +1];

    if (fd == -1)
    {
        write(2, "Error", 5);
        return (1);
    }
    ret = read(fd, buf, BUFF_SIZE);
    buf[ret] = '\0';
    printf("%i", ret);
    printf("%s", buf);

    return (0);
}
