/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:06 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/04 18:19:30 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long int	low;
	long int	high;
	long int	res;
	long int	mid;

	low = 0;
	high = nb / 2;
	res = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
		{
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return (mid);
}

int	ft_is_prime(int nb)
{
	int	num;
	int	i;
	int	prime;

	i = 2;
	prime = 1;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	num = ft_sqrt(nb);
	while (i <= num)
	{
		if ((nb % i) == 0)
			prime = 0;
		i++;
	}
	return (prime);
}
/*int	main (void)
{
		int res = ft_is_prime(961);
		printf("%d", res);
	return (0);
}*/
