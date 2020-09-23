/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:00:53 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/23 16:36:35 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_len(char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		x;

	x = 0;
	if (!(str = malloc(sizeof(char) * str_len(src))))
		return (NULL);
	while (src[x])
	{
		str[x] = src[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
