/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:04:27 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/22 15:32:17 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_error(int x, int y)
{
	if (x <= 0 || y <= 0)
		write(1, "Numero no puede ser menos o igual a zero!\n", 42);
}

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	h;
	int	v;

	v = 1;
	ft_print_error(x, y);
	while (v <= y && y > 0 && x > 0)
	{
		h = 1;
		while (h <= x)
		{
			if ((h == 1 || h == x) && (v == 1 || v == y))
				ft_putchar('o');
			else if (h == 1 || h == x)
				ft_putchar('|');
			else if (v == 1 || v == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			h++;
		}
		ft_putchar('\n');
		v++;
	}
}
