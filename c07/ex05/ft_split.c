/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:20:02 by ytolstob          #+#    #+#             */
/*   Updated: 2023/11/08 18:52:40 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_size(char *str, char *charset)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0)
	{
		while (str[i] != '\0' && !find_sep(str[i], charset))
		{
			i++;
			size++;
		}
		i++;
	}
	return (size);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !find_sep(str[i], charset))
		i++;
	return (i);
}

char	*create_str(char *str, char *charset)
{
	int		len;
	int		i;
	char	*string;

	i = 0;
	len = ft_strlen(str, charset);
	string = malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		index;
	char	**arr;

	i = 0;
	index = 0;
	arr = malloc(sizeof(char *) * (count_size(str, charset) + 1));
	if (arr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && find_sep(str[i], charset))
			i++;
		if (str[i] != '\0')
		{
			arr[index] = create_str(&str[i], charset);
			index++;
			i += ft_strlen(&str[i], charset);
		}
		while (str[i] != '\0' && !find_sep(str[i], charset))
			i++;
	}
	arr[index] = 0;
	return (arr);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	int index = 0;
	char **split;
	(void) argc;
	split = ft_split(argv[1], argv[2]);
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}*/
