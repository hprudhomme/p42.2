/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:43:46 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 16:54:15 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{	
	unsigned int i;

	if (nb < 3 || !(nb % 2))
		return (nb == 2);
	i = 3;
	while (i * i <= (unsigned int)nb)
	{
		if (!(nb % i))
			return (0);
		i += 2;
	}
	return (1);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(18));
}
