/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:20:50 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/13 17:16:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Adds or removes charaters based on the precision.
*/

static int	add_zeros(t_arg *arg, size_t size);
static int	remove_chars(t_arg *arg, size_t size);
static int	set_arg_to_null(t_arg *arg);

/*
** If precision is -1, it is ignored.
*/

int	check_precision(t_arg *arg)
{
	size_t	length;

	//printf("check_precision: result: %s hash: %i\n", arg->result, arg->flags.hashtag);
	if (!arg->type || ft_strchr("cC%", arg->type) || arg->precision == -1)
		return (1);
	if ((!arg->precision &&
		!ft_strcmp((char *)arg->result, "0") &&
		arg->type != 'o') ||
		 (!arg->precision &&
		  !ft_strcmp((char *)arg->result, "0") &&
		  arg->type == 'o' &&
		  !arg->flags.hashtag))
		set_arg_to_null(arg);
	length = (arg->result) ? ft_ustrlen(arg->result) : 0;
	if (ft_strchr("diouxXb", arg->type) && (length < (size_t)arg->precision))
		if (!(add_zeros(arg, (size_t)arg->precision - length)))
			return (0);
	if (arg->type == 's' && length > (size_t)arg->precision)
		remove_chars(arg, (size_t)arg->precision);
	else if (!ft_strchr("diouxXsb", arg->type))
		return (0);
	else if (arg->type == 'n' && arg->precision != -1)
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
	//printf("added zeros: %s\n", zeros);
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
	//printf("remove chars: %s\n", arg->result);
	return (1);
}

static int	set_arg_to_null(t_arg *arg)
{
	//printf("set_arg_to_null\n");
		free(arg->result);
		arg->result = NULL;
		return (1);
}
