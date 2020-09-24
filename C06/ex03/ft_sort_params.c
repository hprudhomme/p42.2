/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:24:18 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/21 19:40:16 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				x;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	x = s1[i] - s2[i];
	return (s1[i] - s2[i]);
}

void	display(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i++ < (argc - 1))
	{
		if (i + 1 < argc && ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			argv[argc + 1] = argv[i + 1];
			argv[i + 1] = argv[i];
			argv[i] = argv[argc + 1];
			i = 0;
		}
	}
	display(argc, argv);
	return (0);
}
