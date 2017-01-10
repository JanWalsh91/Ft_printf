/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:46:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:42:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_alt_form(t_arg *arg);
static int	add_sign(t_arg *arg);

int			check_flags2(t_arg *arg)
{
	//printf("check_alt_form: %s\n", arg->result);
	arg->flags.plus ? add_sign(arg) : 0;
	arg->flags.hashtag ? get_alt_form(arg) : 0;
	return (1);
}

static int	get_alt_form(t_arg *arg)
{
	//printf("get_alt_form\n");
	if (ft_strchr("cdinpsu", arg->type) || !arg->flags.zero)
		return (1);
	if (arg->type == 'o')
		arg->result = ft_ustrjoinfree((UC*)"0", arg->result, 'r');
	if (arg->type == 'x')
		arg->result = ft_ustrjoinfree((UC*)"0x", arg->result, 'r');
	if (arg->type == 'X')
		arg->result = ft_ustrjoinfree((UC*)"0X", arg->result, 'r');
	//add conditions for floating pt conversions	
	//printf("get_alt_form: %s\n", arg->result);
	return (1);
}

static int	add_sign(t_arg *arg)
{
	if (ft_strchr("adefgi", arg->type) && arg->result[0] != '-')
		arg->result = ft_ustrjoinfree((UC*)"+", arg->result, 'r');
	return (1);
}
