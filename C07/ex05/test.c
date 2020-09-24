/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:43:10 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/23 16:19:36 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_is_sep(char c, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_malloc(char **tab, char *str, char *sep)
{
	int i;
	int j;
	int z;
	int x;

	x = 0;
	z = 0;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (sep[++j])
			if (str[i] == sep[j])
			{
				if (!(tab[x] = malloc(sizeof(char) * (z + 3))))
					return (NULL);
				z = -1;
				x++;
				break ;
			}
		z++;
	}
	if (!(tab[x] = malloc(sizeof(char) * (z + 3))))
		return (NULL);
	return (tab);
}

char	**ft_first_malloc(char **tab, char *str, char *sep)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (ft_is_sep(str[i], sep) && !(ft_is_sep(str[i - 1], sep)))
		{
			x++;
		}
		i++;
	}
	if (!(ft_is_sep(str[i - 1], sep)))
		x++;
        printf("nbl = %d\n", x);
	if (!(tab = malloc(sizeof(char*) * (x + 3))))
		return (NULL);
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		x;
	int		y;

	tab = NULL;
	if ((tab = ft_first_malloc(tab, str, charset)) == NULL)
		return (NULL);
	if ((tab = ft_malloc(tab, str, charset)) == NULL)
		return (NULL);
	x = 0;
	y = -1;
	i = 0;
    while (ft_is_sep(str[i], charset))
        i++;
    printf("i = %d\n", i);
    i--;
	while (str[++i])
	{   
		if (ft_is_sep(str[i], charset) && !(ft_is_sep(str[i - 1], charset)))
			{   
                x++;
                y = -1;
            }
		if(!(ft_is_sep(str[i], charset)))
            //printf("x = %d\n", x);
            tab[x][++y] = str[i];
	}
    if (y == -1)
        tab[x] = NULL;
    if (y >= 0)
	    tab[x + 1] = NULL;
	printf("%s\n", tab[0]);
	printf("%s\n", tab[1]);
	printf("%s\n", tab[2]);
	printf("%s\n", tab[3]);
    printf("%s\n", tab[4]);
	return (tab);
}

int main()
{	
	char s[] = "balablablablaa";
	char sep[] = "ab";
	ft_split("    |  | ", " |");
}
