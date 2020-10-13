/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:00:48 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/13 13:43:07 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	var_param_read(t_specvar *var, va_list args)
{
	if (var->specif == 's'  || var->specif == 'S')
		var->hold = va_arg(args, char *);
	else if (var->specif == 'p')
		var->hold = va_arg(args, void *);
	else if ((var->specif == 'c' || var->specif == 'x' || var->specif == 'X'
	|| var->specif == 'u' || var->specif == 'o' || var->specif == 'i'
	|| var->specif == 'd'|| var->specif == 'O' || var->specif == 'U'
	|| var->specif == 'C' || var->specif == 'D') && (!var->mods[DOUBLEL] 
	&& !var->mods[SINGLEL]))
	{
		var->hold = malloc(sizeof(int));
		*((int *)var->hold) = va_arg(args, int);
	}
	else if (var->mods[SINGLEL])
	{
		var->hold = malloc(sizeof(long int));
		*((long int *)var->hold) = va_arg(args, long int);
	}
	else if (var->mods[DOUBLEL])
	{
		var->hold = malloc(sizeof(long long int));
		*((long long int *)var->hold) = va_arg(args, long int);
	}
}

/*

void	write_calls(t_specvar *var)
{
	if (var->specif == 's' ||	var->specif == 'S')
		write_str(var);
	else if ()
}
*/