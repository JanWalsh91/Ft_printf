/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:15:39 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:13:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a type is found, sets it in arg.
*/

int	parse_type(t_data *d, t_arg *arg)
{
	//printf("parse_type\n");
	(ft_strchr("diouxX", arg->type) && arg->precision > 0) ?
		arg->flags.zero = 0 : 0;
	if (ft_strchr("diuoxXcspn%", *d->f))
		arg->type = *d->f;
	else if (ft_strchr("DOUCS", *d->f))
	{
		if (arg->length)
			return (0);
		arg->length = l;
		arg->type = (ft_tolower(arg->type));
	}
	else
		return (0);
	++d->f;
	return (1);
}
