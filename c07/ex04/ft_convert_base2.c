/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_covert_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:34:39 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/08 19:12:39 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	return (i);
}

int	check_error(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (len < 2)
		return (0);
	while (i < len)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	check;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	check = check_error(base, base_len);
	if (check != 0 && *str != '\0')
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (check_value(*str, base) < base_len)
			result = result * base_len + check_value(*str++, base);
	}
	return (result * sign);
}

/*int	main(void)
{
	int	res;
	res = ft_atoi_base("-234", "0123456789");
	printf("%d", res);
	return (0);
}*/
