/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:27:38 by qmattor           #+#    #+#             */
/*   Updated: 2020/11/01 01:32:50 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//	this is to write out the sign on a given variable
void	write_sign(t_specvar *var)
{
	if (var->mods[SIGN] && DEREFERENCE > 0)
			write(1, "+", 1);
		else if (DEREFERENCE < 0)
			write(1, "-", 1);
		else if (var->mods[SPACE] && DEREFERENCE > 0)
			write(1, " ", 1);
}

//	subroutine to write an int, most of it is
//	just placing the signs in the right spot

void	write_int(t_specvar *var)
{
	char	*temp;

	temp = infotoascii(var->hold, var->specif);
	if (var->mods[ZERO])
		write_sign(var);
	if (var->mods[LEFTJUST])
	{
		write_sign(var);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp) + ((var->mods[SIGN] ||
	var->mods[SPACE]) && *((long long *)var->hold) != 0))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[ZERO] && !var->mods[LEFTJUST])
	{
		write_sign(var);
		write(1, temp, ft_strlen(temp));
	}
	else if (var->mods[ZERO])
		write(1, temp, ft_strlen(temp));
	free(temp);
}

/*
void	write_int(t_specvar *var)
{
	char	*temp;

	temp = infotoascii(var->hold, var->specif, var->mods);
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((long long *)var->hold) > 0)
			write(1, var->mods[SPACE] ? " " : "+", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp) + ((var->mods[SIGN] ||
	var->mods[SPACE]) && *((long long *)var->hold) > 0))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((long long *)var->hold) > 0)
			write(1, var->mods[SPACE] ? " " : "+", 1);
		write(1, temp, ft_strlen(temp));
	}
}
*/

//	writing a char is pretty simple

void	write_char(t_specvar *var)
{
	write(1, var->hold, 1);
}

//	because there aren't any signs to worry about placing
//	its a pretty small function

void	write_unsigned(t_specvar *var)
{
	char	*temp;

	temp = infotoascii(var->hold, var->specif);
	if (var->mods[LEFTJUST])
		write(1, temp, ft_strlen(temp));
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
		write(1, temp, ft_strlen(temp));
	free(temp);
}

//	writing a string is the same as ever

void	write_str(t_specvar *var)
{
	write(1, var->hold, ft_strlen(var->hold));
}
