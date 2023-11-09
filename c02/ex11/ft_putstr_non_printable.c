/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:27:14 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/24 13:38:28 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	first;
	int	second;

	while (*str != '\0')
	{
		if (*str < 32)
		{
			first = (*str / 16) + '0';
			second = (*str % 16);
			if (second <= 9)
				second += '0';
			else
				second += 87;
			write(1, "\\", 1);
			write(1, &first, 1);
			write(1, &second, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
