/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wowthatsgross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmattor <qmattor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 06:56:53 by qmattor           #+#    #+#             */
/*   Updated: 2019/12/10 04:16:51 by qmattor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wowthatsgross(char **tab, int *z, const char *s, char c)
{
	while (s[z[1]])
	{
		z[2] = s[z[1]] == c && s[z[1] + 1] == c ? z[2] - 1 : z[2];
		z[0] = s[z[1]] == c && s[z[1] + 1] == c ? z[0] + 1 : z[0];
		if (s[z[1]] == c && s[z[1] + 1] != c)
		{
			tab[z[3]++] = ft_strsub(s, z[1] - z[2] - z[0], z[2]);
			z[2] = -1;
			z[0] = 0;
		}
		z[2]++;
		z[1]++;
	}
}
