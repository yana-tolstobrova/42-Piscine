/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:52 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:05:49 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_throw_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int *nums, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size - 1)
		{
			ft_putchar(nums[row * size + col] + '0');
			ft_putchar(' ');
			col++;
		}
		ft_putchar(nums[row * size + col] + '0');
		ft_putchar('\n');
		row++;
	}
	ft_putchar('\n');
}
