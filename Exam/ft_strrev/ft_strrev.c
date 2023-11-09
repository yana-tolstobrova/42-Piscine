/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:58:02 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 21:41:49 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strrev(char *str)
{
	int		len;
	char	temp;
	int		i;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
	return (str);
}

/*int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_strrev(argv[1]);
	while (argv[1][i] != '\0')
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	return (0);
}*/
