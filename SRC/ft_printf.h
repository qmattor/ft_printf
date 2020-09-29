/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:02 by MacMini           #+#    #+#             */
/*   Updated: 2020/09/29 19:47:18 by MacMini          ###   ########.fr       */
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
void			write_char(char c);
void			write_unsigned(unsigned i);
void			write_long(long i);
#endif
