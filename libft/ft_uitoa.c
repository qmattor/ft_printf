/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:49:16 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/29 19:07:26 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_uitoa(unsigned n)
{
	char	*str;
	long	temp;
	int		i;

	i = 0;
	str = ft_strnew(10);
	temp = n;
	temp == 0 ? str[0] = 48 : 0;
	if (n == 0)
		return (str);
	while (temp > 0)
	{
		str[i++] = (temp % 10) + 48;
		temp /= 10;
	}
	ft_strrev(str);
	return (str);
}
