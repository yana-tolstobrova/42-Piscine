/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:28:54 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/24 16:46:50 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else
			return (-1);
	}
	return (0);
}
/*int	main(void)
{
	char	*s1 = "Atest";
	char	*s2 = "TEST";
	unsigned int	n = 3;
	int	result;
Att	result = ft_strncmp(s1, s2, n);
	printf("%d\n", result);
	return (0);
}*/
