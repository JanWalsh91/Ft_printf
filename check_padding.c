/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:23:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/04 17:31:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If necessary, adds padding based on the field width.
** If field width bigger than length, pad on left with spaces.
*/

static int	add_padding_front(t_arg *arg, char *padding);
static int	add_padding_end(t_arg *arg, char *padding);

int	check_padding(t_arg *arg)
{
	printf("check_padding\n");
	char	*tmp;
	char	padding;

	padding = ' ';
	arg->flags.zero == 1 ? padding = '0' : 0;
	printf("zero flag: %i padding: %c\n", arg->flags.zero, padding);
	if (arg->width > (arg->result_len = update_result_len(arg)))
	{
		printf("width > result_len\n");
		tmp = ft_strnew(arg->width - arg->result_len);
		tmp = ft_memset(tmp, padding, arg->width - arg->result_len);
		if (!tmp)
			return (0);
		if (arg->flags.minus)
			add_padding_end(arg, tmp);
		else
			add_padding_front(arg, tmp);
		printf("added padding: '%s'\n", tmp);
	}
	return (1);
}

static int	add_padding_front(t_arg *arg, char *padding)
{
	printf("add_padding_front\n");
	arg->result = ft_strjoinfree(padding, arg->result, 'r');
	return (1);
}

static int	add_padding_end(t_arg *arg, char *padding)
{
	printf("add_padding_end\n");
	arg->result = ft_strjoinfree(arg->result, padding, 'l');
	return (1);
}
