/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 06:00:48 by MacMini           #+#    #+#             */
/*   Updated: 2020/11/01 01:32:11 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	var_param_read(t_specvar *var, va_list args)
{
	if (var->specif == 's' || var->specif == 'S')
		var->hold = va_arg(args, char *);
	else if (var->specif == 'p')
		var->hold = va_arg(args, void *);
	else if ((var->specif == 'c' || var->specif == 'x' || var->specif == 'X'
	|| var->specif == 'u' || var->specif == 'o' || var->specif == 'i'
	|| var->specif == 'd'|| var->specif == 'O' || var->specif == 'U'
	|| var->specif == 'C' || var->specif == 'D'))
	{
		var->hold = malloc(sizeof(long long int));
		DEREFERENCE = va_arg(args, long long int);
	}
}

void	write_calls(t_specvar *var)
{

	if (var->specif == 'i' || var->specif == 'd' || var->specif == 'D')
		write_int(var);
	else if (var->specif == 'u' || var->specif == 'U')
		write_unsigned(var);
	else if (var->specif == 'x' || var->specif == 'X')
		write_hex(var);
	else if (var->specif == 's' || var->specif == 'S')
		write_str(var);
	else if (var->specif == 'o' || var->specif == 'O')
		write_octal(var);
	else if (var->specif == 'p')
		write_pointer(var);
}

//more shenanagance has ensued

char	*infotoascii(void *hold, char spec)
{
	char			*temp;
	long long int	long_temp;

	temp = NULL;
	long_temp = (long long)(*(int *)hold);
	if (spec == 'i' || spec == 'd' || spec == 'D')
		temp = ft_ltoa(long_temp);
	else if (spec == 'u' || spec == 'U')
		temp = ft_luitoa(long_temp);
	else if (spec == 'x' || spec == 'X')
		temp = ft_luitoab(long_temp, spec == 'x' ?
		"0123456789abcdef" : "0123456789ABCDEF");
	else if (spec == 'o' || spec == 'O')
		temp = ft_luitoab(long_temp, "01234567");
	return (temp);
}
