/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:15:39 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/11 16:36:15 by jwalsh           ###   ########.fr       */
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
	else if (ft_strchr("DOUCS", *d->f))
	{
		arg->length = l;
		arg->type = (ft_tolower(*d->f));
	}
	else
	//{
//		printf("found no type\n");
//		arg->result = NULL;
//	}
		return (0);
	//printf("got type: %i\n", arg->type);
	++d->f;
	return (1);
}
