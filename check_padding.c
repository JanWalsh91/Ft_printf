/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:23:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/09 14:06:30 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If necessary, adds padding based on the field width.
** If field width bigger than length, pad on left with spaces.
*/

static int	add_padding_front(t_arg *arg, UC *padding);
static int	add_padding_end(t_arg *arg, UC *padding);

int	check_padding(t_arg *arg)
{
	//printf("check_padding\n");
	UC	*tmp;
	UC	padding;

	padding = ' ';
	arg->flags.zero == 1 ? padding = '0' : 0;
	//printf("zero flag: %i padding: %c\n", arg->flags.zero, padding);
	if (arg->width && arg->type == 'n')
		return (0);
	arg->result_len = (arg->result) ? ft_strlen((char *)arg->result) : 0;
	if (arg->width > arg->result_len)
	{
		tmp = ft_ustrnew(arg->width - arg->result_len);
		tmp = ft_memset(tmp, padding, arg->width - arg->result_len);
		if (!tmp)
			return (0);
		(arg->flags.minus) ? add_padding_end(arg, tmp) :
			add_padding_front(arg, tmp);
	}
	return (1);
}

static int	add_padding_front(t_arg *arg, UC *padding)
{
	arg->result = ft_ustrjoinfree(padding, arg->result, 'r');
	return (1);
}

static int	add_padding_end(t_arg *arg, UC *padding)
{
	arg->result = ft_ustrjoinfree(arg->result, padding, 'l');
	return (1);
}
