/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:27:38 by qmattor           #+#    #+#             */
/*   Updated: 2020/10/06 04:25:29 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_int(t_specvar *var, va_list args)
{
	char	*temp;

	var->hold = malloc(sizeof(int));
	*((int *)(var->hold)) = va_arg(args, int);
	temp = ft_itoa(*((int *)(var->hold)));
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
			write(1, var->mods[SIGN] && var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
			write(1, var->mods[SIGN] && !var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	free(temp);
}

void	write_char(t_specvar *var, va_list args)
{
	var->hold = malloc(sizeof(int));
	*((int *)(var->hold)) = va_arg(args, int);
	write(1, var->hold, 1);
}

void	write_unsigned(t_specvar *var, va_list args)
{
	char	*temp;

	var->hold = malloc(sizeof(unsigned int));
	*((int *)(var->hold)) = va_arg(args, unsigned int);
	temp = ft_uitoa(*((int *)(var->hold)));
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
			write(1, var->mods[SIGN] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
			write(1, var->mods[SIGN] && !var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	//write(1, var->hold, 1);
}

void	write_str(t_specvar *var, va_list args)
{
	var->hold = va_arg(args, char *);
	write(1, var->hold, ft_strlen(var->hold));
}

void	write_long(t_specvar *var, va_list args)
{
	char	*temp;

	var->hold = malloc(sizeof(int));
	*((long int *)(var->hold)) = va_arg(args, int);
	temp = ft_ltoa(*((long int *)(var->hold)));
	if (var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
			write(1, var->mods[SIGN] && var->mods[ZERO] ? "+" : " ", 1);
		write(1, temp, ft_strlen(temp));
	}
	while (var->width-- > ft_strlen(temp))
		write(1, var->mods[ZERO] ? "0" : " ", 1);
	if (!var->mods[LEFTJUST])
	{
		if ((var->mods[SIGN] || var->mods[SPACE]) && *((int *)(var->hold)) > 0)
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
