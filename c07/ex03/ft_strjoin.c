/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:06:25 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/03 13:04:03 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	find_length(int size, char **strs, char *sep)
{
	int	i;
	int	strs_len;
	int	sep_len;
	int	len;

	i = 0;
	strs_len = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		strs_len += ft_strlen(strs[i]);
		i++;
	}
	len = strs_len + ((size - 1) * sep_len) + 1;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;

	len = find_length(size, strs, sep);
	if (len <= 0)
		len = 1;
	res = malloc(sizeof(char *) * len);
	res[0] = '\0';
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(res, strs[i]);
		if (i != size - 1)
			ft_strcat(res, sep);
		i++;
	}
	return (res);
}
