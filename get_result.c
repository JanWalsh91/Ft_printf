/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:58:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/03 12:27:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(t_data *d, t_arg *arg)
{
	if (arg->type == 'd' || arg->type == 'i')
		get_int(d, arg);
	else if (ft_strchr("ouxX", arg->type))
		get_unsigned_int(d, arg);
	else if (arg->type == 'c' && !get_char(d, arg))
		return (0);
	else if (arg->type == 's' && !get_string(d, arg))
		return (0);
	else if (arg->type == 'p' && !get_address(d, arg))
		return (0);
	printf("result: %s\n", arg->result);
	return (1);
}
