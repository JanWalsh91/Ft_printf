/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:23:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/12 16:05:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** If necessary, adds padding based on the field width.
 ** If field width bigger than length, pad on left with spaces.
 */

static UC	*get_padding(t_arg *arg, UC padding);
static int	fix_sign(t_arg *arg, char padding);
static int	add_padding_front(t_arg *arg, UC *padding);
static int	add_padding_end(t_arg *arg, UC *padding);

int	check_padding(t_arg *arg)
{
	UC	*tmp;
	UC	padding;

	padding = ' ';
	arg->flags.zero == 1 ? padding = '0' : 0;
	if (arg->width && arg->type == 'n')
		return (0);
	arg->result_len = (arg->result) ? ft_ustrlen(arg->result) : 0;
	if (arg->width > arg->result_len)
	{
		if (!(tmp = get_padding(arg, padding)))
			return (0);
		(arg->flags.minus) ? add_padding_end(arg, tmp) :
			add_padding_front(arg, tmp);
		if (ft_strchr("aAdDeEfFgGi", arg->type))
			fix_sign(arg, padding);
	}
	//printf("result: %s\n", arg->result);
	return (1);
}

static UC	*get_padding(t_arg *arg, UC padding)
{
	UC	*tmp;
	int	size;

	size = 0;
	if (arg->flags.hashtag && (arg->flags.space || arg->flags.zero))
	{
		ft_strchr("xX", arg->type) ? size = -2 : 0;
		ft_strchr("oO", arg->type) ? size = -1 : 0;
	}
	if (ft_strchr("aAdDeEfFgGi", arg->type))
	{
		//printf("neg int: %i\n", arg->neg_int);
		(arg->flags.plus || arg->flags.space) &&
			!arg->flags.minus ? --size : 0;
		//printf("updated size: %i\n", size);
	}
	//printf("width: %i, len:%i,size:%i\n", arg->width, arg->result_len, size);
	tmp = ft_ustrnew(arg->width - arg->result_len + size);
	tmp = ft_memset(tmp, padding, arg->width - arg->result_len + size);
	//printf("padding to add: %s\n", tmp);
	return (tmp);
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

static int	fix_sign(t_arg *arg, char padding)
{
	int			i;

	if (arg->neg_int && padding != ' ')
	{
	 i = 0;
		while (arg->result[i] == padding)
			++i;
		//printf("before swap: %s\n", arg->result);
	//	printf("swapping: %c and %c\n", *arg->result, *(arg->result + i));
		ft_swap((int *)(arg->result), (int *)(arg->result + i));
		//printf("swap result: %s\n", arg->result);
		return (1);
	}
	else
		return (0);
}
