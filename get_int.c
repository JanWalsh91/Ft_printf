/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:27:01 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/30 18:49:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the number for i and d
*/

int		get_int(t_data *d, t_arg *arg)
{
	if (arg->length == l)
		arg->result = ft_itoa_base((char)va_arg(d->ap, int), 10);
	else if (arg->length == h)
		arg->result = ft_itoa_base((short)va_arg(d->ap, int), 10);
	else if (arg->length == none)
		arg->result = ft_itoa_base((int)va_arg(d->ap, int), 10);
	else if (arg->length == l || arg->length == z)
		arg->result = ft_itoa_base((long)va_arg(d->ap, long), 10);
	else if (arg->length == ll)
		arg->result = ft_itoa_base((long long)va_arg(d->ap, long long), 10);
	else if (arg->length == j)
		arg->result = ft_itoa_base((intmax_t)va_arg(d->ap, intmax_t), 10);
	else
		return (0);
	return (1);
}
