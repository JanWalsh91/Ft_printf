/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_percent_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 10:56:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/11 12:02:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for a second percent sign and updates the result string if necessary.
*/

int	check_percent_sign(t_data *d, t_arg *arg)
{
	if (*d->f != '%')
		return (0);
	arg->result = ft_ustrjoinfree(arg->result, (UC*)"%", l);
	*d->f ? ++d->f : 0;
	return (1);
}
