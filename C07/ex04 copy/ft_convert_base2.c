/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:03:05 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/21 19:59:10 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
				|| base[i] == '\r'
				|| base[i] == '\n' || base[i] == '\t'
				|| base[i] == '\v' || base[i] == '\f')
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

int		ft_is_in_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_rev_tab(char *str, int size, int n)
{
	int i;
	int j;
	int t;

	i = -1;
	j = size;
	while (++i < --j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
	if (n % 2)
	{
		i = size;
		while (i > 0)
		{
			str[i] = str[i - 1];
			i--;
		}
		str[0] = '-';
	}
	return (str);
}

int		ft_skip_space(char *nbr)
{
	int i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\r' || nbr[i] == '\n' ||
			nbr[i] == '\t' || nbr[i] == '\v' || nbr[i] == '\f')
		i++;
	return (i);
}

int		ft_is_neg(char *nbr, int i)
{
	int n;

	n = 0;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			n++;
		i++;
	}
	return (n);
}
