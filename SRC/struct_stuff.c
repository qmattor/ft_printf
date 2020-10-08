/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 05:16:26 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/06 11:35:25 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specvar	*create_ele()
{
	t_specvar	*temp;

	temp = malloc(sizeof(t_specvar));
	temp->width = 0;
	return (temp);
}

void	del_var(t_specvar *var)
{
	free(var->mods);
	free(var);
}