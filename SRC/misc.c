/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:08:47 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/14 20:51:12 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char		*point_to_str(unsigned long n, char *syms)
{
	char			*str;
	unsigned long	temp;
	int				i;

	i = 0;
	str = ft_strnew(10);
	temp = n;
	temp == 0 ? str[0] = syms[0] : 0;
	if (n == 0)
		return (str);
	temp = temp < 0 ? -temp : temp;
	while (temp > 0)
	{
		str[i++] = syms[(temp % ft_strlen(syms))];
		temp /= ft_strlen(syms);
	}
	ft_strrev(str);
	return (str);
}
