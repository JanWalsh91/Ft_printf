/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:21:50 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/04 17:29:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 
*/

int		parse_arg(t_data *d)
{
	printf("---parse_arg: at char: %c/%i---\n", *d->f, *d->f);
	t_arg	arg;

	if (*d->f == 0 && *d->f != '%')
		return (1);
	if (check_percent_sign(d))
		return (1);
	else if (!init_arg(&arg) ||
		//!parse_parameter(d, &arg) ||
		!parse_flags(d, &arg) ||
		!parse_width(d, &arg) ||
		!parse_precision(d, &arg) ||
		!parse_length(d, &arg) ||
		!parse_type(d, &arg) ||
		!check_type(d, &arg) ||
		!check_precision(&arg) ||
		!check_flags(&arg) ||
		!check_padding(&arg))
		return (0);
	d->s = ft_strjoinfree(d->s, arg.result, l) ;
	//printf("update string: %s\n", d->s);
	return (1);
}
