/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:27:38 by qmattor           #+#    #+#             */
/*   Updated: 2020/09/29 19:22:07 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_int(int i)
{
	char	*temp;

	temp = ft_itoa(i);
	write(1, temp, ft_strlen(temp));
	free(temp);
}

void	write_char(char c)
{
	write(1, &c, 1);
}
/*
void	write_long(long i)
{
	
}
*/
void	write_unsigned(unsigned i)
{
	char	*temp;

	temp = ft_uitoa(i);
	write(1, temp, ft_strlen(temp));
	free(temp);
}
/*
void	write_float(float f)
{
	unsigned long	left;
	unsigned long	right;

	left = f;
	f -= left;
	write(1, ".", 1);
}
*/