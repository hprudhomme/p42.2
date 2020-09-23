int		ft_str_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int     res_len(char *base_to, int nbr)
{   
    int i = 0;
    while (nbr != 0)
    {
        nbr = nbr / ft_str_len(base_to);
        i++;
    }
    printf("res_len = %d\n", i);
    return (i);
}

char	*ft_res_final(char *base_to, int dec, char *res_final, int res_len)
{   
    int nbr;

    nbr = dec;
    printf("buzz = %d\n", res_len);
    res_final[res_len] = '\0';
    res_len = res_len - 1;
    while (res_len != 0)
    {   
        res_final[res_len] = base_to[nbr % ft_str_len(base_to)];
        printf("zzz %c\n", base_to[nbr % ft_str_len(base_to)]);
        nbr = nbr / ft_str_len(base_to);
        res_len--;
    }
    res_final[res_len] = base_to[nbr % ft_str_len(base_to)];
    return res_final;
}

int main()
{
    char base[] = "0123456789abcdef";
    int x = 123;
    char res_final[res_len(base, x)];
    int res_length;
    res_length = res_len(base, x);

    printf("%s\n", ft_res_final(base, x, res_final, res_length));
}