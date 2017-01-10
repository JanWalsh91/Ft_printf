/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:27:01 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:24:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the number for i and d
*/

static int	remove_sign(t_arg *arg);

int		get_int(t_data *d, t_arg *arg)
{
	if (arg->length == hh)
		arg->result = (UC *)ft_itoa_base((char)va_arg(d->ap, int), 10);
	else if (arg->length == h)
		arg->result = (UC *)ft_itoa_base((short)va_arg(d->ap, int), 10);
	else if (arg->length == none)
		arg->result = (UC *)ft_itoa_base((int)va_arg(d->ap, int), 10);
	else if (arg->length == l || arg->length == z)
		arg->result = (UC *)ft_itoa_base((long)va_arg(d->ap, long), 10);
	else if (arg->length == ll)
		arg->result = (UC *)ft_itoa_base((LL)va_arg(d->ap, LL), 10);
	else if (arg->length == j)
		arg->result = (UC *)ft_itoa_base((intmax_t)va_arg(d->ap, intmax_t), 10);
	else
		return (0);
	if (arg->result && *arg->result == '-')
		remove_sign(arg);
	return (1);
}

static int	remove_sign(t_arg *arg)
{
	UC	*tmp;

	tmp = NULL;
	tmp = arg->result;
	arg->result = ft_ustrdup(arg->result + 1);
	free(tmp);
	arg->neg_int = 1;
	return (1);
}
