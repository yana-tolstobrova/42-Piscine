/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:35:53 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/08 21:12:44 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);

char	*reserve_space(long int nbr, int len, char *base)
{
	int		i;
	char	*result;

	i = 0;
	if (nbr < 0)
		i++;
	if (nbr < len)
		i++;
	else
	{
		reserve_space(nbr / len, len, base);
		i++;
	}
	result = malloc(sizeof(char *) * (i + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

char	*reverse_string(char *str, int len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*convert(long int nbr, char *base, char *result)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		result[i++] = '-';
		nbr = -nbr;
	}
	while (nbr >= len)
	{
		result[i++] = base[nbr % len];
		nbr /= len;
	}
	result[i++] = base[nbr];
	result[i] = '\0';
	result = reverse_string(result, i);
	return (result);
}

int	check_base(char *base_to)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(base_to);
	if (!base_to[i] || len < 2)
		return (0);
	while (i < len)
	{
		j = i + 1;
		if (base_to[i] == '-' || base_to[i] == '+' || base_to[i] == ' '
			|| (base_to[i] >= 9 && base_to[i] <= 13))
			return (0);
		while (j < len)
		{
			if (base_to[i] == base_to[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		base_ok;
	int		len;
	char	*result;

	len = ft_strlen(base_to);
	num = ft_atoi_base(nbr, base_from);
	result = reserve_space(num, len, base_to);
	if (result == NULL)
		return (NULL);
	base_ok = check_base(base_to);
	if (base_ok == 1)
		return (convert(num, base_to, result));
	else
		return (NULL);
}

/*int	main(void)
{
	printf("%s", ft_convert_base("4253", "0123456789", "01"));
	return (0);
}*/
