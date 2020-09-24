/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:14:29 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/22 20:54:22 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int					str_len(char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*str;
	int		x;

	if (!(str = malloc(sizeof(char) * str_len(src))))
		return (NULL);
	x = 0;
	while (src[x])
	{
		str[x] = src[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*tab;

	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		tab[i].size = str_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
	}
	tab[i].str = 0;
	return (tab);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puts(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

 void ft_show_tab(struct s_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		ft_puts(par->str);
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_puts(par->copy);
		par++;
	}
}

int main(int argc, char **argv)
{	
	ft_show_tab(ft_strs_to_tab(argc, argv));
}
