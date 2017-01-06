/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:56:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/06 16:51:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for a second percent sign and updates the result string if necessary.
*/

int	check_percent_sign(t_data *d)
{
	//printf("check_percent_sign. string: %s\n", d->s);
	if (*d->f != '%')
		return (0);
	d->s = ft_ustrjoinfree(d->s, (UC*)"%", l);
	*d->f ? ++d->f : 0;
	printf("update string; %s\n", d->s);
	return (1);
}
