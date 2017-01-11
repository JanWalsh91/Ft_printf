/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:14:24 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/11 12:25:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a comma is found, sets the precision in arg.
*/

int	parse_precision(t_data *d, t_arg *arg)
{
	//printf("parse_precision\n");

	// add condiiton for * or *m$
	// if you do, check if negative.
	if (!(*d->f == '.'))
		return (1);
	++d->f;
	if (!*d->f)
		return (0);
	arg->precision = ft_isdigit(*d->f) ? ft_atoi(d->f): 0;
	while (*d->f && ft_isdigit(*d->f))
		++d->f;
	//printf("precision: %i\n", arg->precision);
	return (1);
}
