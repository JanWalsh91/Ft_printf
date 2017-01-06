/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:52:52 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/02 15:18:37 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the string for s
*/

int		get_string(t_data *d, t_arg *arg)
{
	if (arg->length == none)
		arg->result = (char *)va_arg(d->ap, char *);
	else if (arg->length == l)
		arg->result = (char *)va_arg(d->ap, wchar_t *);
	printf("GOT STRING: %s\n", arg->result);
	return (arg->length == none || arg->length == l) ? 1 : 0;
}
