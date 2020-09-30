/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:46:29 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 00:43:02 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_and_call(va_list args, char spec)
{
	void	*holder;			//all pointers are the same length so I can just lie to the computer

	if (spec == 'c')			//char
	{
		holder = (int *)malloc(sizeof(int));
		*((int *)(holder)) = va_arg(args, int);
		write_char(*((int *)(holder)));
	}
	else if (spec == 'i' || spec == 'd' || spec == 'D')
	{
		holder = (int *)malloc(sizeof(int));
		*((int *)(holder)) = va_arg(args, int);
		write_int(*((int *)(holder)));
	}
	else if (spec == '%')
		write(1, "%", 1);
	else if (spec == 's' || spec == 'S')
	{
		holder = va_arg(args, char *);
		write(1, holder, ft_strlen(holder));
	}
	else if (spec == 'o' || spec == 'O')
	{
		holder = (int *)malloc(sizeof(int));
		*((int *)(holder)) = va_arg(args, int);
		write_octal(*((int *)(holder)));
	}
	else if (spec == 'x')
	{
		holder = (int *)malloc(sizeof(int));
		*((int *)(holder)) = va_arg(args, int);
		write_hex_lower(*((int *)(holder)));
	}
	else if (spec == 'X')
	{
		holder = (int *)malloc(sizeof(int));
		*((int *)(holder)) = va_arg(args, int);
		write_hex_upper(*((int *)(holder)));
	}

}