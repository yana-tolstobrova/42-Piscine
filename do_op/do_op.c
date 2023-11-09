/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:10:28 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/09 23:50:30 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	ft_putnbr(int num)
{
	int	i;

	i = 0;
	if (num == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		if (num < 10)
		{
			num = num + 48;
			write(1, &num, 1);
		}
		else
		{
			ft_putnbr(num / 10);
			ft_putnbr(num % 10);
		}
	}
}

void	do_op(char *str1, char *op, char *str2)
{
	int	res;

	if (op[0] == '+')
		res = ft_atoi(str1) + ft_atoi(str2);
	else if (op[0] == '-')
		res = ft_atoi(str1) - ft_atoi(str2);
	else if (op[0] == '/')
		res = ft_atoi(str1) / ft_atoi(str2);
	else if (op[0] == '*')
		res = ft_atoi(str1) * ft_atoi(str2);
	else
		res = ft_atoi(str1) % ft_atoi(str2);
	ft_putnbr(res);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		do_op(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}
