/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_MAIN.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:31:32 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 00:44:03 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>


int main(void)
{
    ft_printf("praise %s %x %X\n", "the sun", INT_MAX, INT_MAX);
	printf("%x %X\n", INT_MAX, INT_MAX);
}
