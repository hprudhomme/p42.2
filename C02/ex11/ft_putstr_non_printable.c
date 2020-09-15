/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:26:27 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/14 19:34:45 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(char c)
{
	char *base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

int		ft_char_is_not_printable(char c)
{
	if (c < 32 || c == 127)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_char_is_not_printable(str[i]))
		{
			ft_hex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
