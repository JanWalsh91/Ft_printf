/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 13:12:56 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 11:59:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If at least one flags is found, sets it in arg. I HAS NOT BEEN PARSED FOR YET
*/

int	parse_flags(t_data *d, t_arg *arg)
{
	//printf("parse_flags\n");
	while (*d->f && ft_strchr("#0-+ 'I", *d->f))
	{
		*d->f == '#' ? arg->flags.hashtag = 1 : 0;
		*d->f == '\'' ? arg->flags.single_quote = 1 : 0;
		*d->f == 'I' ? arg->flags.i = 1 : 0;
		*d->f == '0' && arg->flags.minus == 0 ? arg->flags.zero = 1 : 0;
		*d->f == '-' ? arg->flags.minus = 1 : 0;
		*d->f == '-' ? arg->flags.zero = 0 : 0;
		*d->f == '+' ? arg->flags.plus = 1 : 0;
		*d->f == '+' ? arg->flags.space = 0 : 0;
		*d->f == ' ' && arg->flags.plus == 0 ? arg->flags.space = 1 : 0;
		++d->f;
	}
	//printf("flags: #:%i ':%i i:%i -:%i 0:%i ' ':%i +:%i\n", arg->flags.hashtag, arg->flags.single_quote, arg->flags.i, arg->flags.minus, arg->flags.zero, arg->flags.space, arg->flags.plus);
	return (*d->f ? 1 : 0);
}
