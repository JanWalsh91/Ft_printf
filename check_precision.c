/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:20:50 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/11 16:47:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Adds or removes charaters based on the precision.
*/

static int	add_zeros(t_arg *arg, size_t size);
static int	remove_chars(t_arg *arg, size_t size);

int	check_precision(t_arg *arg)
{
	size_t	length;

	//printf("check_precision\n");
	if (!arg->type || ft_strchr("cC%", arg->type) || arg->precision == -1)
		return (1);
	if (!arg->precision && !ft_strcmp((char *)arg->result, "0"))
	{
		free(arg->result);
		arg->result = NULL;
		return (1);
	}
	length = (arg->result) ? ft_strlen((char *)arg->result) : 0;
	if (ft_strchr("diouxX", arg->type) && (length < (size_t)arg->precision))
	{
		if (!(add_zeros(arg, (size_t)arg->precision - length)))
			return (0);
	}
	if (arg->type == 's' && length > (size_t)arg->precision)
		remove_chars(arg, (size_t)arg->precision);
	else if (!ft_strchr("diouxXs", arg->type))
		return (0);
	else if (arg->type == 'n' && arg->precision != 0)
		return (0);
	return (1);
}

static int	add_zeros(t_arg *arg, size_t size)
{
	UC *zeros;

	if (!(zeros = ft_ustrnew(size + 1)))
		return (0);
	ft_memset(zeros, '0', size);
	arg->result = ft_ustrjoinfree(zeros, arg->result, 'b');
	return (1);
}

static int	remove_chars(t_arg *arg, size_t size)
{
	UC *newstr;

	if (!(newstr = ft_ustrnew(size)))
		return (0);
	newstr = ft_ustrncat(newstr, arg->result, size);
	free(arg->result);
	arg->result = newstr;
	return (1);
}
