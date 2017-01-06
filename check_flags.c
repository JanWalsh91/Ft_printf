/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:11:59 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/04 17:54:36 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**
*/

static int	get_alt_form(t_arg *arg);
static int	add_space(t_arg *arg);
static int	add_sign(t_arg *arg);

int	check_flags(t_arg *arg)
{
	printf("check_flags\n");
	(arg->flags.hashtag) ? get_alt_form(arg) : 0;
	(arg->flags.space) ? add_space(arg) : 0;
	(arg->flags.plus) ? add_sign(arg) : 0;
	return (1);
}

static int	get_alt_form(t_arg *arg)
{
	if (ft_strchr("cdinpsu", arg->type))
		return (1);
	if (arg->type == 'o')
		arg->result = ft_strjoinfree("0", arg->result, 'r');
	if (arg->type == 'x')
		arg->result = ft_strjoinfree("0x", arg->result, 'r');
	if (arg->type == 'X')
		arg->result = ft_strjoinfree("0X", arg->result, 'r');
	//add conditions for floating pt conversions

	return (1);
}

static int add_space(t_arg *arg)
{
	if (ft_strchr("adefgi", arg->type) && arg->result[0] != '-')
		arg->result = ft_strjoinfree(" ", arg->result, 'r');
	return (1);
}

static int add_sign(t_arg *arg)
{
	if (ft_strchr("adefgi", arg->type) && arg->result[0] != '-')
		arg->result = ft_strjoinfree("+", arg->result, 'r');
	return (1);
}

