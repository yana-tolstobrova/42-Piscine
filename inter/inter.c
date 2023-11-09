/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:51:58 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/09 21:59:09 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i;
	int	j;
	int	arr[256] = {0};

	i = 0;
	j = 0;
	while (s2[i])
	{
		if (arr[s2[i]] == 0)
			arr[s2[i]] = 1;
		i++;
	}

	i = 0;
	while (s1[i])
	{
		if (arr[s1[i]] == 1)
		{
			arr[s1[i]] = 2;
			write(1, &s1[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
