/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:36:20 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/24 12:51:20 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0')
		{
			if (i == size)
			{
				i--;
				break ;
			}
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (i);
}
