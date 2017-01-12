/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_result_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 17:08:02 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 16:06:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Recalculates the length of the argument result so far.
*/

int	update_result_len(t_arg *arg)
{
	printf("update_arg_length: ");
	arg->result_len = 0;
	if (arg->result && *arg->result)
	{
		while (arg->result[arg->result_len])
			++arg->result_len;
	}
	printf("%i\n", arg->result_len);
	return (arg->result_len);
}
