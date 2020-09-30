/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 00:35:18 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 00:37:04 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoab(unsigned n, char *syms)
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
