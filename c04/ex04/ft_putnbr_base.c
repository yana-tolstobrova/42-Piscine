/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:52:28 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/30 20:16:05 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	convert(long int nbr, int len, char *base)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < len)
		ft_putchar(base[nbr]);
	else
	{
		convert(nbr / len, len, base);
		ft_putchar(base[nbr % len]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_strlen(base);
	if (!base[i] || len < 2)
		return ;
	while (i < len)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return ;
		while (j < len)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
	convert(nbr, len, base);
}
