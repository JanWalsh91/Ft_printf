/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:52:52 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 15:02:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gets the string for s
*/

int		get_string(t_data *d, t_arg *arg)
{
	wchar_t	*tmp;

	//printf("get_string\n");
	if (arg->length == none)
		arg->result = (UC *)ft_ustrdup((UC *)va_arg(d->ap, char *));
	else if (arg->length == l)
	{
		tmp =  va_arg(d->ap, wchar_t *);
		while (*(tmp++))
			arg->result = ft_ustrjoinfree(arg->result, ft_wctostr(*tmp), 'l');
	}
	if (!arg->result)
		arg->result = ft_ustrdup((UC *)"(null)");
	//printf("GOT STRING: %s\n", arg->result);
	return ((arg->length == none || arg->length == l) ? 1 : 0);
}
