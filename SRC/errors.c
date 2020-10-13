/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 06:20:36 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/13 10:52:16 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This file contains error handling
*/

int		invalid_mods()
{
	write(2, "\nft_printf: invalid mod encountered\n", 37);
	exit(1);
	return (0);
}

int		double_mod()
{
	write(2, "\nft_printf: double mod encountered\n", 36);
	exit(1);
	return (0);
}
