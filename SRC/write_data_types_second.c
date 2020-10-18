/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_types_second.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:12:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/17 20:45:29 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	same as first write data type but extended

void	write_octal(t_specvar *var)
{
	char	*temp;

	temp = ft_uitoab(*((int *)(var->hold)), "01234567");
	if (var->mods[LEFTJUST])
	{
		if (var->mods[POUND])
			write(1, "0", 2);								//uses a '0' instead of the 'O'
		write(1, temp, ft_strlen(temp));
	}if (var->mods[POUND] && var->mods[ZERO])
			write(1, "0", 1);
	while (var->width-- > (var->mods[POUND] ? ft_strlen(temp) + 1
	: ft_strlen(temp)))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if (var->mods[POUND] && !var->mods[ZERO])
			write(1, "0", 1);
		write(1, temp, ft_strlen(temp));
	}
	free(temp);
}
void	write_hex(t_specvar *var)
{
	char			*temp;

	temp = ft_uitoab(*((int *)var->hold), var->specif == 'x' ?
	"0123456789abcdef" : "0123456789ABCDEF");
	if (var->mods[LEFTJUST])
	{
		if (var->mods[POUND])
			write(1, var->specif == 'x' ? "0x" : "0X", 2);
		write(1, temp, ft_strlen(temp));
	}
	if (var->mods[ZERO] && var->mods[POUND])
			write(1, var->specif == 'x' ? "0x" : "0X", 2);
	while (var->width-- > (var->mods[POUND] ? ft_strlen(temp) + 2
	: ft_strlen(temp)))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if (var->mods[POUND] && !var->mods[ZERO])
			write(1, var->specif == 'x' ? "0x" : "0X", 2);
		write(1, temp, ft_strlen(temp));
	}
	free(temp);
}

void	write_pointer(t_specvar *var)
{
	char			*temp;

	temp = point_to_str((long int)var->hold, "0123456789abcdef");
	write(1, "0x", 2);
	write(1, temp, ft_strlen(temp));
	free(temp);
}
