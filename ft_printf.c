/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:15:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 13:35:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes to the standard output according to the format strings and arguments
** prodvided.
** Parses the format strings until an argument is found, then parses and
** converts arguments, joining them to the output string.
** Returns the number of bytes written or -1 if an error occurs.
*/

static int	ft_printf_error(t_data d);

int	ft_printf(const char * restrict format, ...)
{
	t_data		d;
	int			ret;
	//format ? printf("input string: %s\n", format) : 0;
	va_start(d.ap, format);
	set_data(&d, (char *)format);
	while (d.f && *d.f)
	{
		if (!parse_until_arg(&d) || !parse_arg(&d))
			return (ft_printf_error(d));
		//printf("check\n");
	}
	//printf("check1\n");
	d.s ? d.byte_count = ft_strlen((char *)d.s) : 0;
	d.byte_count += d.null_char;
	ret = write(1, d.s, d.byte_count);
	va_end(d.ap);
	return (ret < 0 ? ret : d.byte_count);
}

static int	ft_printf_error(t_data d)
{
	d.byte_count = (d.s) ? ft_strlen((char *)d.s) : 0;
	d.byte_count += d.null_char;
	write(1, d.s, d.byte_count);
	return (-1);
}
