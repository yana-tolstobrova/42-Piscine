/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:10:14 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 23:20:01 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_countdown(void)
{
	int	i;

	i = '9';
	while (i >= '0' && i <= '9')
	{
		write(1, &i, 1);
		i--;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	ft_countdown();
	return (0);
}
