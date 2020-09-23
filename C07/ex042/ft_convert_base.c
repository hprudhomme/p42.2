/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hprudhom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:03:19 by hprudhom          #+#    #+#             */
/*   Updated: 2020/09/21 19:58:13 by hprudhom         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		check_base(char *base);
int		ft_is_in_base(char *base, char c);
char	*ft_rev_tab(char *str, int size, int n);
int		ft_skip_space(char *nbr);
int		ft_is_neg(char *nbr, int i);

int		ft_str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_smllc(char *base, int dec)
{
	int i;
	int base_to_len;

	base_to_len = ft_str_len(base);
	i = 0;
	while (dec)
	{
		dec = dec / base_to_len;
		i++;
	}
	return (i - 1);
}

int		ft_find_res_dec(char c, char *base, int dec)
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
	dec = dec * base_len + i;
	return (dec);
}

char	*ft_res_final(char *base_to, int dec, char *res_final, int n)
{   
	int res_len;
	res_len = !(n % 2) ? ft_smllc(base_to, dec) + 1 : ft_smllc(base_to, dec) + 2;
    res_final[res_len] = '\0';
    res_len = res_len - 1;
    while (res_len > n % 2)
    {   
        res_final[res_len] = base_to[dec % ft_str_len(base_to)];
        dec = dec / ft_str_len(base_to);
        res_len--;
    }
	res_final[res_len] = base_to[dec % ft_str_len(base_to)];
	if (n % 2)
		res_final[0] = '-';
    return res_final;
} 

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		n;
	char	*res_final;
	int		dec;

	dec = 0;
	if (check_base(base_from))
	{
		i = ft_skip_space(nbr);
		n = ft_is_neg(nbr, i);
		while (nbr[i] == '-' || nbr[i] == '+')
			i++;
		while (ft_is_in_base(base_from, nbr[i]))
		{
			dec = ft_find_res_dec(nbr[i], base_from, dec);
			i++;
		}
		if (!(res_final = malloc(sizeof(char) *
				(ft_smllc(base_to, dec) + (n % 2) + 1))))
			return (NULL);
		return(res_final = ft_res_final(base_to, dec, res_final, n));
	}
	return (NULL);
}

int main()
{
	char n[] = "-15620";
	char base[] = "01234567";
	char base2[] = "0123456789";

	printf("%s\n", ft_convert_base(n, base, base2));
}
