/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_types_second.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:12:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 00:40:57 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_octal(int i)
{
	char			*temp;

	temp = ft_uitoab(i, "01234567");
	write(1, temp, ft_strlen(temp));
}

void	write_hex_lower(int i)
{
		char			*temp;

	temp = ft_uitoab(i, "0123456789abcdef");
	write(1, temp, ft_strlen(temp));
}
void	write_hex_upper(int i)
{
		char			*temp;

	temp = ft_uitoab(i, "0123456789ABCDEF");
	write(1, temp, ft_strlen(temp));
}