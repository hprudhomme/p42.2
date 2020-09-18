/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:18:13 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/16 18:10:31 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			check_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long int	ft_nb_neg(long int nb)
{
	ft_putchar('-');
	return (-nb);
}

void		ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			nbr_final[100];
	int			size_base;
	long int	nb;

	if (check_base(base))
	{
		nb = nbr;
		if (nb == 0)
			ft_putchar(nb + 48);
		if (nb < 0)
			nb = ft_nb_neg(nb);
		size_base = 0;
		i = 0;
		while (base[size_base])
			size_base++;
		while (nb)
		{
			nbr_final[i] = base[nb % size_base];
			nb = nb / size_base;
			i++;
		}
		while (i-- > 0)
			ft_putchar(nbr_final[i]);
	}
}
