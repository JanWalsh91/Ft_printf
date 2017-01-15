/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:35:30 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/15 14:41:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_user_input(t_data *d, char **input);
static int	get_code_values(char *c);

int			get_color(t_data *d, t_arg *arg)
{
	char	*code;

	init_arg(arg);
	get_user_input(d, &code);
	get_code_values(code);
	arg->result = (UC *)ft_strjoinfree((char *)arg->result, code, 'o');
	return (1);
}

static int	get_user_input(t_data *d, char **input)
{
	int		i;

	i = 0;
	while (d->f[i] && d->f[i] != '}')
		++i;
	if (!(*input = ft_strnew(i)))
		return (0);
	*input = ft_strncpy(*input, d->f, i);
	while (*d->f && *d->f != '}')
		++d->f;
	++d->f;
	i = -1;
	while (input && input[++i])
		((*input)[i] == ' ') ? (*input)[i] = ',' : 0;
	i = -1;
	ft_strtolower(*input);
	return (1);
}

static int	get_code_values(char *c)
{
	int		i;

	i = -1;
	!ft_strcmp(c, "eoc") || !ft_strcmp(c, "")
		? c = ft_strdupfree(c, "\e[0m") : 0;
	!ft_strcmp(c, "bold") || !ft_strcmp(c, "b") ?
		c = ft_strdupfree(c, "\e[1m") : 0;
	!ft_strcmp(c, "dim") || !ft_strcmp(c, "d") ?
		c = ft_strdupfree(c, "\e[2m") : 0;
	!ft_strcmp(c, "italics") || !ft_strcmp(c, "i") ?
		c = ft_strdupfree(c, "\e[3m") : 0;
	!ft_strcmp(c, "underline") || !ft_strcmp(c, "u")
		? c = ft_strdupfree(c, "\e[4m") : 0;
	!ft_strcmp(c, "red") ? c = ft_strdupfree(c, RED) : 0;
	!ft_strcmp(c, "green") ? c = ft_strdupfree(c, GREEN) : 0;
	!ft_strcmp(c, "blue") ? c = ft_strdupfree(c, BLUE) : 0;
	!ft_strcmp(c, "magenta") ? c = ft_strdupfree(c, MAGENTA) : 0;
	!ft_strcmp(c, "cyan") ? c = ft_strdupfree(c, CYAN) : 0;
	!ft_strcmp(c, "yellow") ? c = ft_strdupfree(c, YELLOW) : 0;
	!ft_strcmp(c, "pink") ? c = ft_strdupfree(c, PINK) : 0;
	!ft_strcmp(c, "orange") ? c = ft_strdupfree(c, ORANGE) : 0;
	!ft_strcmp(c, "black") ? c = ft_strdupfree(c, BLACK) : 0;
	c && c[0] != '\e' ? c = ft_strdupfree(c, "") : 0;
	return (1);
}
