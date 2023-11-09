/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2023/10/28 14:14:45 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:46:51 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_throw_error(void);
int		ft_strlen(char *str);
void	ft_asignation(char *argv, int size, int *nums, int *result);
void	resolver(int *result, int *nums, int *position, int size);
void	ft_free_memo(int *nums, int *result);
int		ft_check_view_col(int *count_v_col, int col, int size, int *views);

void	ft_verify(char *argv)
{
	int	argv_len;
	int	size;
	int	*nums;
	int	*result;
	int	position[2];

	argv_len = ft_strlen(argv);
	if ((argv_len + 1) % 8 != 0)
	{
		ft_throw_error();
		return ;
	}
	size = (argv_len + 1) / 8;
	nums = (int *)malloc(size * 4 * 4);
	result = (int *)malloc(size * size * 4);
	ft_asignation(argv, size, nums, result);
	position[0] = 0;
	position[1] = 0;
	resolver(result, nums, position, size);
	ft_free_memo(nums, result);
}

void	ft_asignation(char *argv, int size, int *nums, int *result)
{
	int	i;
	int	count;
	int	argv_len;

	i = 0;
	count = 0;
	argv_len = ft_strlen(argv);
	while (i < argv_len)
	{
		if (argv[i] > '0' && argv[i] <= size + '0'
			&& (argv[i + 1] == ' ' || i == argv_len - 1))
		{
			nums[count++] = argv[i] - '0';
			i += 2;
		}
		else
		{
			ft_throw_error();
			return ;
		}
	}
	i = 0;
	while (i < size * size)
		result[i++] = 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_errors(int size, int *count_v_col, int *views)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_check_view_col(count_v_col, i, size, views) == 1)
			return (1);
		i++;
	}
	free(count_v_col);
	return (0);
}

int	ft_check_duplicated(int size, int *count_n_col, int *count_n_row)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		if (count_n_col[i] > 1 || count_n_row[i] > 1)
			return (1);
		i++;
	}
	free(count_n_col);
	free(count_n_row);
	return (0);
}
