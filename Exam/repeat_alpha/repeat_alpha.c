/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:04:04 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/27 13:22:20 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	while(str[i] != '\0')
		{
			count = 0;
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				count = str[i] - 97;;
				while (count-- && count >= 0)
				   write(1, &str[i], 1);
			}
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				count = str[i] - 65;
				while (count-- && count >= 0)
					write(1, &str[i], 1);
			}
			write(1, &str[i], 1);
			i++;
		}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
