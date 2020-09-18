/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:40:01 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/18 13:06:27 by hprudhom         ###   ########lyon.fr   */
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

int		ft_find_res(char c, char *base, int res)
{
	int i;
	int base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			break ;
		i++;
	}
	res = res * base_len + i;
	return (res);
}

int		ft_atoi(char *str, char *base)
{
	int i;
	int n;
	int res;

	n = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\a' || str[i] == '\b'
			|| str[i] == '\v' || str[i] == '\f')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	res = 0;
	while (ft_is_in_base(base, str[i]))
	{
		res = ft_find_res(str[i], base, res);
		i++;
	}
	res = res * n;
	return (res);
}

int		ft_atoi_base(char *str, char *base)
{
	int res;

	res = 0;
	if (check_base(base))
	{
		res = ft_atoi(str, base);
	}
	return (res);
}
