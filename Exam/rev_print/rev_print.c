/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:09:37 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 16:09:57 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_print(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	while (--size >= 0)
		write(1, &str[size], 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	else
		write(1, "\n", 1);
}
