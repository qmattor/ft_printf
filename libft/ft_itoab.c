/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:17:00 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 01:07:17 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static char	*addneg(char *str)
{
	char	*temp;

	temp = str;
	str = ft_strjoin("-", str);
	free(temp);
	return (str);
}

char		*ft_itoab(int n, char *syms)
{
	char		*str;
	int			flag;
	long long	temp;
	int			i;

	i = 0;
	str = ft_strnew(20);
	temp = n;
	temp == 0 ? str[0] = syms[0] : 0;
	if (n == 0)
		return (str);
	flag = temp < 0 ? 1 : 0;
	temp = temp < 0 ? -temp : temp;
	while (temp > 0)
	{
		str[i++] = syms[(temp % ft_strlen(syms))];
		temp /= ft_strlen(syms);
	}
	ft_strrev(str);
	str = flag ? addneg(str) : str;
	return (str);
}
