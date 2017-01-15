/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:13:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/14 19:17:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a field width is found, sets it in arg.
*/

static int	parse_wildcard(t_data *d, t_arg *arg);
static int	parse_num(t_data *d, t_arg *arg);

int	parse_width(t_data *d, t_arg *arg)
{
	//printf("parse_width: ");
	if (!ft_isdigit(*d->f) && *d->f != '*')
		return (1);
	while (ft_isdigit(*d->f) || *d->f == '*')
	{
		//printf("parsing width: %c\n", *d->f);
		(ft_isdigit(*d->f)) ? parse_num(d, arg) : 0;
		//printf("width: %i\n", arg->width);
		//printf("parsing width: %c\n", *d->f);
		(*d->f == '*') ? parse_wildcard(d, arg) : 0;
		//printf("width: %i\n", arg->width);
	}
	return (1);
}

static int	parse_wildcard(t_data *d, t_arg *arg)
{
	if ((arg->width = va_arg(d->ap, int)) < 0)
	{
		arg->width = (arg->width == -2147483648) ? 2147483647 : -arg->width;
		arg->flags.minus = 1;
	}
	++d->f;
	return (1);
}

static int	parse_num(t_data *d, t_arg *arg)
{
	arg->width = ft_atoi(d->f);
	while (*d->f && ft_isdigit(*d->f))
		++d->f;
	return (1);
}
