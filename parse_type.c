/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:15:39 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 18:37:33 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a type is found, sets it in arg.
*/

int	parse_type(t_data *d, t_arg *arg)
{
	(ft_strchr("dDiIoOuUxX", arg->type) && arg->precision > 0) ?
		arg->flags.zero = 0 : 0;
	if (ft_strchr("diuoxXcspn%", *d->f))
		arg->type = *d->f;
	else if (ft_strchr("DOUSC", *d->f))
	{
		arg->length == hh ? arg->length = h : 0;
		arg->length == h ? arg->length = none : 0;
		arg->length == none ? arg->length = l : 0;
		arg->length == l ? arg->length = ll : 0;
		arg->length == ll ? arg->length = ll : 0;
		ft_strchr("CS",*d->f) ? arg->length = l : 0;
		arg->type = (ft_tolower(*d->f));
	}
	else 
	{
		//printf("no arg type\n");
		arg->result = ft_ustrnew(2);
		arg->result[0] = *d->f;
		arg->type = 0;
		//arg->result = (UC *)ft_strdup("\0");
	}
	//else
	//	return (0);
	//printf("parse type: %i, result: %s\n", arg->type, arg->result);
	++d->f;
	return (1);
}
