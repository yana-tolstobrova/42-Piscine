/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytolstob <ytolstob@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:23:58 by ytolstob          #+#    #+#             */
/*   Updated: 2023/10/26 20:55:02 by ytolstob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
   octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
   octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
   octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
   return (octet);
}
