/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_until_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:42:24 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/03 11:23:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_until_arg(t_data *d)
{
	printf("parse_until_arg: at char: %c/%i\n", *d->f, *d->f);
	int	i;
	char *tmp;

	i = 0;
	while (*d->f && *d->f != '%')
	{
		++d->f;
		++i;
	}
	d->length += i;
	if (!(tmp = (char *)malloc(d->length + 1)))
		return (0);
	ft_strncpy(tmp, d->f - i, i);
	d->s = ft_strjoinfree(d->s, tmp, l);
	*d->f ? ++d->f : 0;
	printf("udpate string: %s\n", d->s);
	return (1);
}
