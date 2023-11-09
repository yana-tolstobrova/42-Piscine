/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:52 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:05:49 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_count_n_row(int *count_n_row, int *position, int size, int *result);
void	ft_count_n_col(int *count_n_col, int *position, int size, int *result);
void	ft_count_v_col(int *count_v_col, int *position, int size, int *result);
int		ft_check_view_row(int *result, int *views, int row, int size);
int		ft_check_errors(int size, int *count_v_col, int *views);
int		ft_check_duplicated(int size, int *count_n_col, int *count_n_row);
int		ft_check_front(int *nums, int size);
int		*check_view(int *nums, int size);
void	ft_remem(int *count_n_row, int *count_n_col,
			int *count_v_col, int size);

int	check(int *result, int *views, int size)
{
	int	*position;
	int	*count_n_row;
	int	*count_n_col;
	int	*count_v_col;

	position = NULL;
	count_n_col = NULL;
	count_n_row = NULL;
	count_v_col = NULL;
	ft_remem(count_n_row, count_n_col, count_v_col, size);
	position[0] = -1;
	while (position[0]++ < size)
	{
		position[1] = -1;
		while (position[1]++ < size)
		{
			if (result[position[0] * size + position[1]] > 0)
			{
				ft_count_n_row(count_n_row, position, size, result);
				ft_count_n_col(count_n_col, position, size, result);
			}
			ft_count_v_col(count_v_col, position, size, result);
		}
		if (ft_check_view_row(result, views, position[0], size))
			return (1);
	}
	if (ft_check_errors(size, count_v_col, views)
		|| ft_check_duplicated(size, count_n_col, count_n_row))
		return (1);
	return (0);
}

int	*check_view(int *nums, int size)
{
	int			max;
	int			i;
	int			count;
	static int	result[2];

	result[0] = ft_check_front(nums, size);
	count = 1;
	max = nums[size - 1];
	i = size - 1;
	while (i >= 0)
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
		i--;
	}
	result[1] = count;
	return (result);
}

int	ft_check_view_row(int *result, int *views, int row, int size)
{
	int	*a;

	a = check_view(&result[row * size], size);
	if ((a[0] != -1 && a[0] != views[2 * size + row])
		|| (a[1] != -1 && a[1] != views[3 * size + row]))
		return (1);
	return (0);
}

int	ft_check_view_col(int *count_v_col, int col, int size, int *views)
{
	int	*a;

	a = check_view(&count_v_col[col * size], size);
	if ((a[0] != -1 && a[0] != views[0 * size + col])
		|| (a[1] != -1 && a[1] != views[1 * size + col]))
		return (1);
	return (0);
}

void	ft_remem(int *count_n_row, int *count_n_col, int *count_v_col, int size)
{
	int	i;

	count_n_row = (int *)malloc(size * size * 4);
	count_n_col = (int *)malloc(size * size * 4);
	count_v_col = (int *)malloc(size * size * 4);
	i = 0;
	while (i < size * size)
	{
		count_n_row[i] = 0;
		count_n_col[i] = 0;
		i++;
	}
}
