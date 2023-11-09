/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:42:34 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/01 19:15:04 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long int	low;
	long int	high;
	long int	res;
	long int	mid;

	low = 1;
	high = nb / 2;
	res = 0;
	if (nb == 0 || nb == 1)
		return (nb);
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
	return (0);
}
