/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:05:24 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 20:01:03 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] - 13 < 'a')
				str[i] = 'z' - (12 - (str[i] - 'a'));
			else
				str[i] -= 13;
		}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				if (str[i] - 13 < 'A')
					str[i] = 'Z' - (12 - (str[i] - 'A'));
				else
				str[i] -= 13;
			}
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	else
		write(1, "\n", 1);
}
