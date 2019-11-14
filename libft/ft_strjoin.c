/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avornane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:09:42 by avornane          #+#    #+#             */
/*   Updated: 2019/11/04 12:21:45 by avornane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*fresh;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total = (ft_strlen(s1) + ft_strlen(s2)) + 2;
	fresh = ft_strnew(total);
	if (!s1 || !s2)
		return (NULL);
	if (fresh == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		fresh[i] = s1[i];
		i++;
	}
	ft_strcat(fresh, s2);
	return (fresh);
}
