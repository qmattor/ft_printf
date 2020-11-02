/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:38:02 by MacMini           #+#    #+#             */
/*   Updated: 2020/11/01 01:32:26 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# define SPECIALCHAR "sSpdDioOuUxXcC\45"
# define MODCHAR "0#-+lhzj "
# define ZERO 0
# define POUND 1
# define LEFTJUST 2
# define SIGN 3
# define SINGLEL 4
# define DOUBLEL 9
# define SINGLEH 5
# define DOUBLEH 10
# define ZFLAG 6
# define JFLAG 7
# define SPACE 8
# define DEREFERENCE *((long long *)var->hold)
typedef struct				s_specvar
{
	int						width;
	char					specif;
	char					*mods;
	void					*hold;
}							t_specvar;

//ft_printf.c
int							ft_printf(char *str, ...);

//more_writes.c
void						write_long_octal(t_specvar *var);


//write_data_type.c
void						write_int(t_specvar *var);
void						write_char(t_specvar *var);
void						write_str(t_specvar *var);
void						write_unsigned(t_specvar *var);

//write_data_types_second.c
void						write_octal(t_specvar *var);
void						write_hex(t_specvar *var);
void						write_pointer(t_specvar *var);


//variable_param.c
/****************************REMOVED**************************************/
/*void						parse_and_call(t_specvar *var, va_list args);*/
/*void						check_mods(va_list args, char *str);*/
/*************************************************************************/
//struct_stuff.c
void						del_var(t_specvar *var);
t_specvar					*create_ele();
//errors.c
int							invalid_mods();
//int						double_mod();

//parsing.c
char						*get_str_lit(char *str);
char						get_spec(char *str_ltr);
char						*main_write(char *str, va_list args);

//misc.c
long long					ft_abs(long long num);
char						*ft_ltoa(long long int n);
char						*ft_luitoab(unsigned long long n, char *dstr);
char						*ft_luitoa(unsigned long long n);
char						*point_to_str(unsigned long n, char *syms);

//debugging.c
void						print_mods(char *mods);

//switches.c
void						var_param_read(t_specvar *var, va_list args);
void						write_calls(t_specvar *var);
char						*infotoascii(void *hold, char spec);
//width
int							get_width(char *str);
char						check_not_width(char *str_ltr, char *place);
#endif
