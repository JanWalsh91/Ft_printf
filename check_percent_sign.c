/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:56:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/03 13:20:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_percent_sign(t_data *d)
{
	//printf("check_percent_sign. string: %s\n", d->s);
	if (*d->f != '%')
		return (0);
	d->s = ft_strjoinfree(d->s, "%", l);
	*d->f ? ++d->f : 0;
	printf("update string; %s\n", d->s);
	return (1);
}
