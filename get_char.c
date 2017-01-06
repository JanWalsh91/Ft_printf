/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:04:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/02 15:25:43 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the int/wint_t argument converted to unsigned char/wchar_t
*/

int		get_char(t_data *d, t_arg *arg)
{
	//printf("get_char\n");
	if (!(arg->result = (char *)malloc(2)))
		return (0);
	if (arg->length == l)
	{
		arg->result[0] = (wchar_t)va_arg(d->ap, wint_t);
		arg->result[1] = '\0';
	}
	else if (arg->length == none)
	{
		arg->result[0] = (UC)va_arg(d->ap, int);
		arg->result[1] = '\0';
	}
	else
		return (0);
	return (1);
}
