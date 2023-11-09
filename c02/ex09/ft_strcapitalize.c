/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:14 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/24 12:48:13 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	next_cap;

	i = 0;
	next_cap = 1;
	while (str[i])
	{
		if (!next_cap && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] < 'a' || str[i] > 'z')
			next_cap = 0;
		if (str[i] >= 'a' && str[i] <= 'z' && next_cap)
		{
			str[i] -= 32;
			next_cap = 0;
		}
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			next_cap = 1;
		i++;
	}
	return (str);
}
