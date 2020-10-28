/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 05:08:02 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/27 20:39:47 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	this file was just for debugging purposes

void	print_mods(char *mods)
{
	int x;

	x = 0;
	write(1, "0, #, -, +, l, h, z, j,  ,ll,hh,\n", 33);
	while (x < 11)
		write(1, mods[x++] ? "1, " : "0, ", 4);
}