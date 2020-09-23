/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 13:30:29 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/23 19:18:56 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		size_of_words(char **strs, int size)
{
	int full_size;
	int i;
	int j;

	full_size = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		full_size += j;
		i++;
	}
	return (full_size);
}

int		size_of_sep(char *sep, int size)
{
	int i;

	i = 0;
	while (sep[i])
		i++;
	return (i * (size - 1));
}

char	*ft_join(int size, char **strs, char *sep, char *tab)
{
	int		i;
	int		j;
	int		z;

	z = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			tab[z] = strs[i][j];
			z++;
			j++;
		}
		j = 0;
		while (sep[j] && i < size - 1)
		{
			tab[z] = sep[j];
			z++;
			j++;
		}
	}
	tab[z] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;

	if (size == 0)
		return (tab = "");
	if (!(tab = malloc(sizeof(char) * (size_of_words(strs, size) +
			size_of_sep(sep, size) + 1))))
		return (NULL);
	return (ft_join(size, strs, sep, tab));
}
