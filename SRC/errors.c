/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 06:20:36 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/27 20:30:06 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This file contains error handling
**	This could honestly be a lot better more in depth
*/

int		invalid_mods()
{
	write(2, "\nft_printf: invalid mod encountered\n", 37);
	exit(1);
	return (0);
}

/*	apperently this isn't a thing
**	int		double_mod()
**	{
**	write(2, "\nft_printf: double mod encountered\n", 36);
**	exit(1);
**	return (0);
**	}
*/