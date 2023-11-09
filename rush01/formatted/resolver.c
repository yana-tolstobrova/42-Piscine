/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:46:52 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:05:49 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check(int *result, int *views, int size);
int		ft_correct_board(int *result, int *row, int *col, int size);
void	ft_wrong_board(int *result, int *row, int *col, int size);
void	resolver(int *result, int *nums, int *position, int size);
void	ft_print_result(int *nums, int size);
void	ft_throw_error(void);
void	ft_update_position(int *next_col, int *next_row, int size);

void	resolver(int *result, int *nums, int *position, int size)
{
	if (result[position[1] * size + position[0]] == 0)
		result[position[1] * size + position[0]] = 1;
	if (check(result, nums, size) == 1)
	{
		if (ft_correct_board(result, &position[1], &position[0], size) == 1)
			return ;
	}
	else
		ft_wrong_board(result, &position[1], &position[0], size);
	resolver(result, nums, position, size);
}

int	ft_correct_board(int *result, int *row, int *col, int size)
{
	int	next_col;
	int	next_row;

	next_col = *col;
	next_row = *row;
	if (next_col == size - 1 && next_row == size - 1)
	{
		ft_print_result(result, size);
		return (1);
	}
	if (next_col == size - 1)
	{
		next_row++;
		next_col = 0;
	}
	else
		next_col++;
	*row = next_row;
	*col = next_col;
	return (0);
}

void	ft_wrong_board(int *result, int *row, int *col, int size)
{
	int	i;

	if (result[*row * size + *col] == size)
	{
		result[(*row * size + *col)] = 0;
		i = 1;
		if (*row == 0 && *col == 1)
		{
			ft_throw_error();
			return ;
		}
		while (result[(*row * size + *col) - i] == size)
		{
			result[(*row * size + *col) - i] = 0;
			ft_update_position(col, row, size);
			i++;
		}
		result[(*row * size + *col) - i] += 1;
		ft_update_position(col, row, size);
	}
	else
		result[*row * size + *col] += 1;
}

void	ft_update_position(int *next_col, int *next_row, int size)
{
	if (next_col == 0)
	{
		*next_row -= 1;
		*next_col = size - 1;
	}
	else
		*next_col -= 1;
}
