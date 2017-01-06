/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_until_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:42:24 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/06 17:54:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_until_arg(t_data *d)
{
	printf("parse_until_arg: at char: %c/%i\n", *d->f, *d->f);
	int	i;
	UC	*tmp;

	i = 0;
	while (*d->f && *d->f != '%')
	{
		++d->f;
		++i;
	}
	if (!(tmp = (UC *)malloc(i + 1)))
		return (0);
	ft_strncpy((char *)tmp, d->f - i, i);
	d->s = ft_ustrjoinfree(d->s, tmp, l);
	*d->f ? ++d->f : 0;
	//printf("udpate string: %s\n", d->s);
	return (1);
}
