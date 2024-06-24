/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:59:39 by ytolstob          #+#    #+#             */
/*   Updated: 2024/06/21 23:14:45 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(char *argv)
{
	int		fd;
	int		sz;
	char	buf[2024];

	fd = open(argv, O_RDONLY);
	sz = read(fd, buf, sizeof(buf));
	if (sz > 0)
		write(1, buf, sz);
	if (sz == -1)
		write(2, "Cannot read file.\n", 18);
	close(fd);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		ft_display_file(argv[1]);
	}
}
