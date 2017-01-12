/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:59:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 12:32:19 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(t_data *d, t_arg *arg)
{
	//printf("check type: result:  %s\n", arg->result);
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
	else if (arg->type == 'n' && !set_byte_count(d, arg))
		return (0);
	else if (arg->type == '%' && !get_percent(arg))
		return (0);
	!arg->type ? arg->result = (UC *)ft_strdup("\0") : 0;
	//	printf("check\n");
	//	arg->result = (UC *)ft_strdup("\0");
	
	//printf("check_type: result: %s\n", arg->result);
	return (1);
}
