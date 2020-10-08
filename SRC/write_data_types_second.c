/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_types_second.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:12:57 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/05 03:55:19 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_octal(t_specvar *var, va_list args)
{
	char	*temp;

	var->hold = malloc(sizeof(unsigned int));
	*((int *)(var->hold)) = va_arg(args, unsigned int);
	temp = ft_uitoab(*((int *)(var->hold)), "01234567");
	write(1, temp, ft_strlen(temp));
	free(temp);
}
void	write_hex_lower(t_specvar *var, va_list args)
{
	char			*temp;

	var->hold = malloc(sizeof(unsigned int));
	*((unsigned int *)(var->hold)) = va_arg(args, unsigned int);
	temp = ft_uitoab(*((int *)var->hold), "0123456789abcdef");
	write(1, temp, ft_strlen(temp));
	free(temp);
}
void	write_hex_upper(t_specvar *var, va_list args)
{
	char			*temp;

	var->hold = malloc(sizeof(unsigned int));
	*((unsigned int *)(var->hold)) = va_arg(args, unsigned int);
	temp = ft_uitoab(*((int *)(var->hold)), "0123456789ABCDEF");
	write(1, temp, ft_strlen(temp));
	free(temp);
}
void	write_pointer(t_specvar *var, va_list args)
{
	char			*temp;

	var->hold = malloc(sizeof(unsigned int));
	var->hold = va_arg(args, void *);
	temp = point_to_str((long int)var->hold, "0123456789abcdef");
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
