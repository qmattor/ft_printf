/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:08:47 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/27 20:40:15 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_abs(long long num)
{
	if (num < 0)
		return (-num);
	return (num);
}

char		*ft_ltoa(long long int n)
{
	char		*str;
	long long	temp;
	int			i;

	i = 0;
	str = ft_strnew(21);
	temp = n;
	temp == 0 ? str[0] = 48 : 0;
	if (n == 0)
		return (str);
	while (temp != 0)
	{
		str[i++] = (ft_abs(temp) % 10) + 48;
		temp /= 10;
	}
	ft_strrev(str);
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

char		*ft_luitoa(unsigned long long n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(21);						// max digits in an unsigned long long is 20
	n == 0 ? str[0] = 48 : 0;
	if (n == 0)
		return (str);
	while (n > 0)
	{
		str[i++] = (n % 10) + 48;
		n /= 10;
	}
	ft_strrev(str);
	return (str);
}

char		*ft_luitoab(unsigned long long n, char *dstr)
{
	char	*str;
	int		i;
	int		base;

	i = 0;
	base = ft_strlen(dstr);
	str = ft_strnew(24);						// max digits in an unsigned long long in octal is 23
	n == 0 ? str[0] = 48 : 0;
	if (n == 0)
		return (str);
	while (n > 0)
	{
		str[i++] = dstr[(n % base)];
		n /= base;
	}
	ft_strrev(str);
	return (str);
}
