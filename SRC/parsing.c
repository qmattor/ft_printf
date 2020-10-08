/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 04:46:58 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/06 12:56:06 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//str is the original string
//str_ltr is the string literal in the printf statement

char	*get_str_lit(char *str)
{
	char	*ptr;
	char	*str_ltr;

	ptr = str + 1;
	str_ltr = ft_strnew(20);
	while (*str)
	{
		str++;
		if (ft_strchr(SPECIALCHAR, *str) != NULL)
		{
			str++;
			break ;
		}
	}
	ft_strncpy(str_ltr, ptr, str - ptr);
	return (str_ltr);
}

int		get_width(char *str)
{
	int		x;

	x = 0;
	while (*str)
	{
		x = ft_atoi(str);
		if (x == 0)
			str++;
		else
			break ;
	}
	return (x);
}

void	parse_mods(char	*mods, char *str_ltr)
{
	const char	*modstr;

	modstr = MODCHAR;
	if (ft_strchr(SPECIALCHAR, *str_ltr) != NULL)
		return ;
	while (*str_ltr)
	{
		if (ft_strchr(modstr, *str_ltr) == NULL)
			invalid_mods();
		else
		{
			if (*str_ltr == 'l' && *(str_ltr + 1) == 'l')
			{
				mods[DOUBLEL] = mods[DOUBLEL] ? double_mod() : 1;
				str_ltr++;
			}
			else if (*str_ltr == 'h' && *(str_ltr + 1) == 'h')
			{
				mods[DOUBLEH] = mods[DOUBLEH] ? double_mod() : 1;
				str_ltr++;
			}
			else
			{
				if (mods[ft_strchr(modstr, *str_ltr) - modstr] == 1)
					double_mod();
				mods[ft_strchr(modstr, *str_ltr) - modstr] =  1;
			}
		}
		str_ltr++;
	}
}

char	get_spec(char *str_ltr)
{
	str_ltr--;
	while (*(++str_ltr))
		if (ft_strchr(SPECIALCHAR, *str_ltr))
			break ;
	return (*str_ltr);
}

char	*main_write(char *str, va_list args)
{
	char		*str_ltr;
	int			width;
	char		*mods;
	t_specvar	*var;

	(void)args;
	mods = ft_strnew(10);
	var = malloc(sizeof(t_specvar));
	str_ltr = get_str_lit(str);
	width = get_width(str_ltr);
	printf("\n%s", str_ltr);
	parse_mods(mods, str_ltr);
	var->mods = mods;
	var->width = width;
	var->specif = get_spec(str_ltr);
	return (str + ft_strlen(str_ltr));
}