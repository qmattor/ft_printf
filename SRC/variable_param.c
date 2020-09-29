/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:46:29 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/29 19:56:10 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_and_call(va_list args, char spec)
{
	void	*holder;			//all pointers are the same length so I can just lie to the computer

	if (spec == 'c')			//char
	{
		holder = malloc(sizeof(char));
		(*holder) = va_arg(args, char);
	}
	else if (spec == 'i' || spec == 'd')
	{
		//int
	}


}