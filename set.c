/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:04:30 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/31 16:39:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Sets data
*/

void	set_data(t_data *d, char *format)
{
	d->indicate_param = 0;
	d->f = format;
	d->s = NULL;
	d->length = 0;
}
