/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MacMini <MacMini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 05:16:26 by MacMini           #+#    #+#             */
/*   Updated: 2020/10/27 20:20:13 by MacMini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	this is for managing stuctures, probably could have mushed it into another file
**	but it looks cleaner this way
*/

t_specvar	*create_ele()
{
	t_specvar	*temp;

	temp = malloc(sizeof(t_specvar));
	temp->width = 0;
	return (temp);
}

void	del_var(t_specvar *var)
{
	if (var->specif != 's' && var->specif != 'S' && var->specif != 'p')
		free(var->hold);
	free(var->mods);
	free(var);
}