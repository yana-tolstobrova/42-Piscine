/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:09:15 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/04 18:20:10 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	low;
	long int	high;
	long int	res;
	long int	mid;

	low = 1;
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

int	ft_find_next_prime(int nb)
{
	int	is_prime;

	is_prime = ft_is_prime(nb);
	if (is_prime == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
}
