/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:08:41 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 15:00:12 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*search_and_replace(char *s1, char let_replace, char let_write)
	{
		int	i;

		i = 0;
		while(s1[i] != '\0')
		{
			if (s1[i] == let_replace)
				s1[i] = let_write;
			write(1, &s1[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (s1);
	}

int	main(int argc, char **argv)
{
	if (argc == 4 && (argv[2][0] >= 'a' && argv[2][0] <= 'z' && !argv[2][1]) 
			&& (argv[3][0] >= 'a' && argv[3][0] <= 'z' && !argv[3][1]))
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	else
		write(1, "\n", 1);
	return (0);
}
