/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2023/10/28 14:14:45 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:46:51 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_count_n_row(int *count_n_row, int *position, int size, int *result)
{
	count_n_row[position[0] * size
		+ (result[position[0] * size + position[1]] - 1)] += 1;
}

void	ft_count_n_col(int *count_n_col, int *position, int size, int *result)
{
	count_n_col[position[1] * size
		+ (result[position[0] * size + position[1]] - 1)] += 1;
}

void	ft_count_v_col(int *count_v_col, int *position, int size, int *result)
{
	count_v_col[position[1] * size + position[0]]
		= result[position[0] * size + position[1]];
}

int	ft_check_front(int *nums, int size)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 1;
	max = nums[0];
	while (i < size)
	{
		if (nums[i] == 0)
		{
			count = -1;
			break ;
		}
		else if (nums[i] > max)
		{
			max = nums[i];
			count++;
		}
		i++;
	}
	return (count);
}

void	ft_free_memo(int *nums, int *result)
{
	free(nums);
	free(result);
}
