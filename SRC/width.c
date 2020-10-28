/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 21:42:34 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/25 18:24:38 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_width(char *str)
{
	int		x;

	x = 0;
	while (*str)
	{
		x = ft_atoi(str);
		if (x <= 0)
			str++;
		else
			break ;
	}
	return (x);
}

static int	widthtoi(char *str)
{
	long	res;
	char	*start;

	res = 0;
	start = str;
	if (str == NULL || *str == '0')
		return (0);
	while (1)
	{
		if (*str < '0' || *str > '9')
			break ;
		res = (res * 10) + *str++ - 48;
	}
	return ((int)res);
}

static char	*get_width_ptr(char *str_ltr)
{
	char *start;

	start = str_ltr;
	while (!widthtoi(str_ltr) && *str_ltr)
		str_ltr++;
	if (!*str_ltr)
		return (start);
	return (str_ltr);
}

char		check_not_width(char *str_ltr, char *place)
{
	char	*width_ptr;
	char	*temp;

	width_ptr = get_width_ptr(str_ltr);
	if (place < width_ptr)
		return (0);
	temp = width_ptr;
	while (ft_isdigit(*temp) && *temp)
		if (temp == place)
			return (1);
		else
			temp++;
	return (0);
}
