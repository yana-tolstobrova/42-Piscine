/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmas-pra <jmas-pra@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:40:33 by jmas-pra          #+#    #+#             */
/*   Updated: 2023/10/28 23:43:14 by jmas-pra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_verify(char *argv);
void	ft_throw_error(void);

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_verify(argv[1]);
		return (1);
	}
	else
		ft_throw_error();
	return (0);
}
