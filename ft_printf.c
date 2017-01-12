/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:15:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 16:10:50 by jwalsh           ###   ########.fr       */
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

static int	ft_printf_error(t_data *d);
static int	revert_null_chars(t_data *d);

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
			return (ft_printf_error(&d));
		//printf("check\n");
	}
	//printf("check1\n");
	d.s ? d.byte_count = ft_ustrlen(d.s) : 0;
	d.null_char ? revert_null_chars(&d) : 0;
	ret = write(1, d.s, d.byte_count);
	va_end(d.ap);
	return (ret < 0 ? ret : d.byte_count);
}

static int	ft_printf_error(t_data *d)
{
	d->byte_count = (d->s) ? ft_ustrlen(d->s) : 0;
	d->null_char ? revert_null_chars(d) : 0;
	write(1, d->s, d->byte_count);
	return (-1);
}

static int	revert_null_chars(t_data *d)
{
	int	i;

	i = -1;
	while (d->s && d->s[++i])
		d->s[i] == 255 ? d->s[i] = 0 : 0;
	return (1);
}
