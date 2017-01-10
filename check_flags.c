/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:11:59 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:40:54 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for hashtag, space, minus and apostrphe flags and update the result
** if neceassry.
*/

static int	get_alt_form(t_arg *arg);
static int	add_space(t_arg *arg);
//static int	add_sign(t_arg *arg);
static int	add_commas(t_arg *arg);

int	check_flags(t_arg *arg)
{
	//printf("check_flags\n");
	if (arg->type == 'n' && (arg->flags.hashtag || arg->flags.zero ||
				arg->flags.minus || arg->flags.plus || arg->flags.space ||
				arg->flags.single_quote || arg->flags.i))
		return (0);
	(arg->flags.single_quote) ? add_commas(arg) : 0;
	(arg->flags.hashtag) ? get_alt_form(arg) : 0;
	(arg->flags.space) ? add_space(arg) : 0;
	//(arg->flags.plus) ? add_sign(arg) : 0;
	return (1);
}

static int	get_alt_form(t_arg *arg)
{
	if (ft_strchr("cdinpsu", arg->type) || arg->flags.zero)
		return (1);
	if (arg->type == 'o')
		arg->result = ft_ustrjoinfree((UC*)"0", arg->result, 'r');
	if (arg->type == 'x')
		arg->result = ft_ustrjoinfree((UC*)"0x", arg->result, 'r');
	if (arg->type == 'X')
		arg->result = ft_ustrjoinfree((UC*)"0X", arg->result, 'r');
	//add conditions for floating pt conversions

	return (1);
}

static int	add_space(t_arg *arg)
{
	if (ft_strchr("adefgi", arg->type) && arg->result[0] != '-')
		arg->result = ft_ustrjoinfree((UC*)" ", arg->result, 'r');
	return (1);
}

/*
static int	add_sign(t_arg *arg)
{
	if (ft_strchr("adefgi", arg->type) && arg->result[0] != '-')
		arg->result = ft_ustrjoinfree((UC*)"+", arg->result, 'r');
	return (1);
}
*/

static int	add_commas(t_arg *arg)
{
	int		i;
	int		y;
	int		comma_count;
	UC		*result;

	if (!ft_strchr("diu", arg->type))
		return (0);
	i = 0;
	while (arg->result && arg->result[i])
		++i;
	if (!(comma_count = (i - 1) / 3))
		return (1);
	if (!(result = ft_ustrnew(i + comma_count)))
		return (0);
	y = 0;
	while (--i + comma_count >= 0)
	{
		if (y == 3 && !(y = 0))
			result[i + comma_count--] = ',';
		result[i + comma_count] = arg->result[i];
		++y;
	}
	free(arg->result);
	arg->result = result;
	return (1);
}
