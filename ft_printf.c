/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:15:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/06 17:53:57 by jwalsh           ###   ########.fr       */
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
			return (-1);
		}
	}
	d.byte_count = ft_strlen((char *)d.s);
	while (*d.s) //temporary until byte_count is properly evaluated
		write(1, d.s++, 1);
	//write(1, d.s, d.byte_count);
	va_end(d.ap);
	return (d.byte_count);
}
