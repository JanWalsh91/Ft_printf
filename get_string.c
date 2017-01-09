/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:52:52 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/08 15:08:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the string for s
*/

int		get_string(t_data *d, t_arg *arg)
{
	wchar_t	*tmp;

	if (arg->length == none)
		arg->result = (UC *)va_arg(d->ap, char *);
	else if (arg->length == l)
	{
		tmp =  va_arg(d->ap, wchar_t *);
		while (*(tmp++))
			arg->result = ft_wctostr(*tmp);
	}
	//printf("GOT STRING: %s\n", arg->result);
	return (arg->length == none || arg->length == l) ? 1 : 0;
}
