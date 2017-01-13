/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:14:24 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/13 12:33:28 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Precision is by default set to -1.
** If a period is found, the precision is set to the following number.
** If there is no number, the precision is set to 0.
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
