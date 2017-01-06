/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:15:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/05 17:51:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char * restrict format, ...)
{
	t_data		d;

	printf("input string: %s\n", format);
	va_start(d.ap, format);
	set_data(&d, (char *)format);
	while (d.f && *d.f)
	{
		if (!parse_until_arg(&d) || !parse_arg(&d))
		{
			printf("parse fail\n");
			return (0);
		}
	}
	ft_putstr(d.s);
	va_end(d.ap);
	return (0);
}
