/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:24:14 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 14:34:25 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int i;
	int res;
	
	if(index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_fibonacci(16));
}
