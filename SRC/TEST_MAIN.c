/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_MAIN.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:31:32 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/17 20:44:45 by MacMini          ###   ########.fr       */
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
	ft_printf("%s\n", c);
    printf("%s\n", c);
	ft_printf("%U\n", x);
    printf("%u\n", x);
	ft_printf("%o\n", x);
    printf("%o\n", x);
	ft_printf("%#10x\n", x);
    printf("%#10x\n", x);
	ft_printf("%p\n", p);
    printf("%p\n", p);
 
	// ft_printf("%+13i\n", x);	//these all work in conjunction, also, notably the padding number can be any positive number up to 0x7FFFFFFE
	// ft_printf("%0#x\n", x);		//the # takes precident and also counts as width
	// ft_printf("%-10uA\n", x);
	// ft_printf("%hhi\n", *c);
}
