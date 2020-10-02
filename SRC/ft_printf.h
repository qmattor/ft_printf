/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:02 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/30 01:22:34 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# define SPECIALCHAR "sSpdDioOuUxXcC\45"

int				ft_printf(char *str, ...);
void			write_int(int x);
void			write_char(int c);
void			write_unsigned(unsigned i);
void			write_long(long i);
void			write_octal(int i);
void			parse_and_call(va_list args, char spec);
void			write_hex_lower(int i);
void			write_hex_upper(int i);
void			write_pointer(void *p);
char			*point_to_str(unsigned long n, char *syms);
#endif
