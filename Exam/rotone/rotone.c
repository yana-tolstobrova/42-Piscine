/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:29:28 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/09 21:41:57 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'z')
			write(1, "a", 1);
		else if (str[i] == 'Z')
			write(1, "A", 1);
		else
		{
			if ((str[i] >= 'a' && str[i] < 'z') 
					|| str[i] >= 'A' && str[i] < 'Z')
			{
				str[i] = str[i] + 1;
				write(1, &str[i], 1);
			}
			else
				write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
