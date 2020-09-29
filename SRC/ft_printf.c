/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:41:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/29 19:31:22 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	va_list args;

	va_start(args, str);

	while (ft_strchr(str, '%') != NULL)
	{
		write(1, str, ft_strchr(str, '%') - str);
		str = ft_strchr(str, '%');
		
	}
	write(1, str, ft_strlen(str));
	va_end(args);
	return (0);

			// A 'char' variable will be promoted to 'int'
			// A character literal in C is already 'int' by itself


	va_end(args);
	return (0);
}
