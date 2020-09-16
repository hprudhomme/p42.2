/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:56:57 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 13:24:17 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int 	ft_iterative_factorial(int nb)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (nb > 0)
	{
		res = res * nb;
		nb--;
	}
	return (res);
}

int main()
{
	int x = 10;
	printf("%d", ft_iterative_factorial(x));
	return 0;
}
