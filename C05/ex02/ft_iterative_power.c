/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:25:05 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 13:32:14 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_iterative_power(7, 6));
}
