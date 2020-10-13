/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_MAIN.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:31:32 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/13 11:18:35 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

//	this is just a text file

int main(void)
{
	int		*p;
	char	c[] = "test";
	int		x;

	//	sSpdDioOuUxXcC%

	x = 54321;
	p = &x;
    printf("%i\n", x);
	ft_printf("%ms\n", c);
    // printf("%p\n", p);
	// ft_printf("%p\n", p);
    // printf("%i\n", x);
	// ft_printf("%i\n", x);
    // printf("%d\n", x);
	// ft_printf("%d\n", x);
    // printf("%o\n", x);
	// ft_printf("%o\n", x);
    // printf("%u\n", x);
	// ft_printf("%u\n", x);
    // printf("%x\n", x);
	// ft_printf("%x\n", x);
	// printf("%c\n", *c);
	// ft_printf("%c\n", *c);
	// printf("%%\n");
	// ft_printf("%%\n");
	// printf("%#x\n", x);
	// printf("%x\n", x);
	// ft_printf("%+13i\n", x);	//these all work in conjunction, also, notably the padding number can be any positive number up to 0x7FFFFFFE
	// ft_printf("%0#x\n", x);		//the # takes precident and also counts as width
	// ft_printf("%-10uA\n", x);
	// ft_printf("%hhi\n", *c);
}
