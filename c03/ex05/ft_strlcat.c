/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:18:53 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 12:32:12 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (dest[len] != '\0')
		len++;
	if (size > len)
	{
		while (i < size - len - 1 && src[i] != '\0')
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	if (size <= len)
		return (size + i);
	return (len + i);
}
