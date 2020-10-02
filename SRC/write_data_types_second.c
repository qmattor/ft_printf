/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_types_second.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:12:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 01:23:53 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_octal(int i)
{
	char			*temp;

	temp = ft_uitoab(i, "01234567");
	write(1, temp, ft_strlen(temp));
	free(temp);
}

void	write_hex_lower(int i)
{
	char			*temp;

	temp = ft_uitoab(i, "0123456789abcdef");
	write(1, temp, ft_strlen(temp));
	free(temp);
}
void	write_hex_upper(int i)
{
	char			*temp;

	temp = ft_uitoab(i, "0123456789ABCDEF");
	write(1, temp, ft_strlen(temp));
	free(temp);
}

void	write_pointer(void *p)
{
	char			*temp;

	temp = point_to_str((long int)p, "0123456789abcdef");
	write(1, "0x", 2);
	write(1, temp, ft_strlen(temp));
	free(temp);
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
