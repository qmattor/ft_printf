/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:41:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/11/01 01:31:18 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This contains the called function
*/

int		ft_printf(char *str, ...)
{
	va_list	args;
	int		x;

	x = 0;
	va_start(args, str);
	while (ft_strchr(str, '%') != NULL)
	{
		if (*(str + 1) == '%')
		{
			write(1, "%", 1);
			str++;
		}
		else
		{
			write(1, str, ft_strchr(str, '%') - str);
			str = ft_strchr(str, '%');		// I forgot that this moves the str pointer to the % so that the str_ltr starts from the right spot
			str = main_write(str, args);
		}
		str++;
	}
	write(1, str, ft_strlen(str));
	va_end(args);
	return (0);
}
