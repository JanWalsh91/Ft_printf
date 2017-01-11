/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:09:30 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 16:24:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If a parameter is found, sets it in arg.  UNFINISHED
*/

int	parse_parameter(t_data *d, t_arg *arg)
{
	//printf("parse_parameter\n");
	int	i;

	i = 0;
	if (*d->f && !ft_isdigit(*d->f))
		return (1);
	arg->parameter = ft_atoi(d->f);
	while (d->f[i] && ft_isdigit(d->f[i]))
		++i;
	if (d->f[i] && d->f[i] == '$')
	{
		d->f += i + 1;
		d->indicate_param = 1;
		return (1);
	}
	arg->parameter = 0;
	return (1);
}
