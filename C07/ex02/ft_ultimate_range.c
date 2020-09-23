/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:53:06 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/23 17:03:23 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;

	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min));
	if (!(*range))
		return (-1);
	max = max - min;
	i = -1;
	while (++i < max)
		(*range)[i] = min + i;
	return (max);
}
