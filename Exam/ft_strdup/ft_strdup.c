/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:09:06 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 20:20:15 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dest = (char *)malloc(len * sizeof(char));
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
