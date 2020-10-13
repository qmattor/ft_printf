/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:27:38 by qmattor           #+#    #+#             */
/*   Updated: 2020/10/13 11:18:11 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// this is in need of updates, but it's for writing out specific variable types

//"0, #, -, +, l, h, z, j,  "

//these aren't really the most elegant functions but they work

void	write_int(t_specvar *var)
{
	char	*temp;

	temp = ft_itoa(*((int *)var->hold));
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] && *((int *)var->hold) < 0) || var->mods[SPACE])
			write(1, var->mods[SPACE] ? " " : "+", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
	{
		if (!var->mods[LEFTJUST] && var->mods[ZERO])
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] && *((int *)var->hold) < 0) || var->mods[SPACE])
			write(1, var->mods[SPACE] ? " " : "+", 1);
		write(1, temp, ft_strlen(temp));
	}
}

void	write_char(t_specvar *var)
{
	write(1, var->hold, 1);
}

void	write_unsigned(t_specvar *var)
{
	char	*temp;

	temp = ft_uitoa(*((int *)(var->hold)));
	if (var->mods[LEFTJUST])
	{
		if (var->mods[SIGN] || var->mods[SPACE])
			write(1, var->mods[SIGN] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if (var->mods[SIGN] || var->mods[SPACE])
			write(1, var->mods[SIGN] && !var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
}

void	write_str(t_specvar *var)
{
	write(1, var->hold, ft_strlen(var->hold));
}

void	write_long(t_specvar *var)
{
	char	*temp;

	temp = ft_ltoa(*((long *)var->hold));
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] && *((int *)(var->hold)) > 0) || var->mods[SPACE])
			write(1, var->mods[SIGN] && var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] && *((int *)(var->hold)) > 0) || var->mods[SPACE])
			write(1, var->mods[SIGN] && !var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	free(temp);
}

static char	*addneg(char *str)
{
	char	*temp;

	temp = str;
	str = ft_strjoin("-", str);
	free(temp);
	return (str);
}

char		*ft_ltoa(long int n)
{
	char		*str;
	int			flag;
	long long	temp;
	int			i;

	i = 0;
	str = ft_strnew(20);
	temp = n;
	temp == 0 ? str[0] = 48 : 0;
	if (n == 0)
		return (str);
	flag = temp < 0 ? 1 : 0;
	temp = temp < 0 ? -temp : temp;
	while (temp > 0)
	{
		str[i++] = (temp % 10) + 48;
		temp /= 10;
	}
	ft_strrev(str);
	str = flag ? addneg(str) : str;
	return (str);
}
