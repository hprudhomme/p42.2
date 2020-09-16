/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:04:58 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 13:22:30 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{	
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_recursive_factorial(3));
}
