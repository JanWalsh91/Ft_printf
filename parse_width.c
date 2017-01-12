/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:13:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 16:42:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a field width is found, sets it in arg.
*/

int	parse_width(t_data *d, t_arg *arg)
{
	//printf("parse_width: ");
	if (!ft_isdigit(*d->f))
		return (1);
	arg->width = ft_atoi(d->f);
	while (*d->f && ft_isdigit(*d->f))
		++d->f;
	//printf("%i\n", arg->width);
	return (1);
}
