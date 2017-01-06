/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:15:39 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/04 17:54:37 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a type is found, sets it in arg.
*/

int	parse_type(t_data *d, t_arg *arg)
{
	(ft_strchr("diouxX", arg->type) && arg->precision > 0) ?
		arg->flags.zero = 0 : 0;
	if (ft_strchr("diuoxXcsp", *d->f))
		arg->type = *d->f;
	else if (ft_strchr("DOUCS", *d->f))
	{
		if (arg->length)
			return (0);
		arg->length = 3;
		arg->type = (ft_tolower(*d->f));
	}
	else
		return (0);
	++d->f;
	return (1);
}
