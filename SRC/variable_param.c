/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:46:29 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/06 04:46:30 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


//this file is blanked out. I don't like how its turning out and I'm starting over.
//adding the mods into an already working system is not working well




/*
void	parse_and_call(t_specvar *var, va_list args)
{
	void		(*writer)(t_specvar *temp, va_list args);

	if (var->specif == 'c')			//char
		writer = *write_char;
	else if (var->specif == 'i' || var->specif == 'd' || var->specif == 'D')
		writer = *write_int;
	else if (var->specif == 's' || var->specif == 'S')
		writer = *write_str;
	else if (var->specif == 'o' || var->specif == 'O')
		writer = *write_octal;
	else if (var->specif == 'x')
		writer = *write_hex_lower;
	else if (var->specif == 'X')
		writer = *write_hex_upper;
	else if(var->specif == 'p')
		writer = *write_pointer;
	else if (var->specif == 'u' || var->specif == 'U')
		writer = *write_unsigned;
	else
		writer = *write_char;
	writer(var, args);
}

// assumed input is the input str, starting right after the %

//	I'm starting to realize that this isn't really that complicated, its just a lot of specific things to check
void	check_mods(va_list args, char *str)
{
	int			x;
	t_specvar	*var;
	char		*speclist;
	int			modp;

	var = create_ele(args);
	modp = 0;
	speclist = SPECIALCHAR;
	x = 0;
	while (*str)
	{
		while (*str != speclist[x] && speclist[x++])							//while not a specifier, must be mod
			;
		if (x != 17)															//break if specifer
			break ;
		if (ft_isdigit(*str) && ft_atoi(str) != 0)								//checking for width
		{
			var->width = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else
			var->mods[modp++] = *str;											//must be mod (needs to be fixed)
		str++;
	}
	parse_and_call(var, args);
}

char	*add_mod(t_specvar *var, char *str)
{
	char	temp[10] = MODCHAR;
	char	*ptr;

	ptr = ft_strchr(temp, *str);
	if (ptr == NULL)
		invalid_mods();
	if (*ptr == 'l' && *(str + 1) == 'l')
	{
		var->mods[DOUBLEL] = 1;
		return (str + 2);
	}
	if (*ptr == 'h' && *(str + 1) == 'h')
	{
		var->mods[DOUBLEH] = 1;
		return (str + 2);
	}
	var->mods[temp - ptr] = var->mods[temp - ptr] == 1 ? double_mod() : 1;
	return (str);
}

/*
# define ZERO 0
# define POUND 1
# define LEFTJUST 2
# define SIGN 3
# define SINGLEL 4
# define DOUBLEL 5
# define DOUBLEL 5
# define SINGLEH 6
# define DOUBLEH 7
# define ZFLAG 8
# define JFLAG 9
# define SPACE 10
	if (*str == '0')
		var->mods[ZERO] = 1;
	else if (*str == '#')
		var->mods[POUND] = 1;
	else if (*str == '-')
		var->mods[LEFTJUST] = 1;
	else if (*str == '+')
		var->mods[SIGN] = 1;
	else if (*str == ' ')
		var->mods[SPACE] = 1;
	else if (*str == 'z')
		var->mods[ZFLAG] = 1;
	else if (*str == 'j')
		var->mods[JFLAG] = 1;
	else
	{
		if (*str == 'l' && *(str + 1) != 'l')
			var->mods[SINGLEL] = 1;
		else if (*str == 'h' && *(str + 1) != 'h')
			var->mods[SINGLEH] = 1;
		else
		{
			if (*str == 'l' && *(str + 1) == 'l')
				var->mods[DOUBLEL] = 1;
			else if (*str == 'h' && *(str + 1) == 'h')
				var->mods[DOUBLEH] = 1;
			str++;
		}
	}
	str++;
*/