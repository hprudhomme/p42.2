/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:56:50 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 18:09:27 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	unsigned int i;

	if (nb < 3)
		return (2);
	if (!(nb % 2))
		nb++;
	i = 3;
	while (i * i <= (unsigned int)nb)
	{
		if (!(nb % i))
		{
			nb += 2;
			i = 1;
		}
		i += 2;
	}
	return (nb);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_find_next_prime(90));
}
