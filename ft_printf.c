/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:15:36 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/13 14:40:03 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Writes to the standard output according to the format strings and arguments
** prodvided.
** Parses the format strings until an argument is found, then parses and
** converts arguments. If the argument is valid, concats the conversion
** and the non-argument part of the format string to the output string.
** Returns the number of bytes written or -1 if an error occurs.
*/

static int	revert_null_chars(t_data *d);
static int	write_result(t_data *d, int i);

int	ft_printf(const char * restrict format, ...)
{
	t_data		d;

	va_start(d.ap, format);
	set_data(&d, (char *)format);
	while (d.f && *d.f)
		if (!parse_until_arg(&d) || !parse_arg(&d))
			return (write_result(&d, 0));
	//printf("check1\n");
	return (write_result(&d, 1));
}

/*
** Null chars that have to be displayed are temporarily converted to 255, then
** reverted to '\0' before printing the final output. Simplified parsing
** and contantenation throughout the program.
*/

static int	revert_null_chars(t_data *d)
{
	int	i;

	i = -1;
	while (d->s && d->s[++i])
		d->s[i] == 255 ? d->s[i] = 0 : 0;
	return (1);
}

/*
** Writes the final output string to the standard output and returns the
** byte_count if i is not null, or -1 if i is null (error).
*/

static int write_result(t_data *d, int i)
{
	d->s ? d->byte_count = ft_ustrlen(d->s) : 0;
	d->null_char ? revert_null_chars(d) : 0;
	write(1, d->s, d->byte_count);
	va_end(d->ap);
	return (i ? d->byte_count : -1);
}
