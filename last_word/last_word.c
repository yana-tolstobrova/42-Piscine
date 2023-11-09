/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:03:01 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/09 22:20:19 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	space(char c)
{
	if (c == ' ' || (c >= 9 && c<= 13))
		return (1);
	return (0);
}

void	last_word(char *str)
{
	while (*str)
		str++;
	str--;
	while (space(*str))
		str--;
	while (*str	&& !space(*str))
			str--;
	str++;
	while (*str	&& !space(*str))
			write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
