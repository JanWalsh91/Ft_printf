/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:23:52 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:43:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UI unsigned int
# define UC unsigned char
# define LL long long
# include "libft/libft.h"
# include <wchar.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //////////////

/*
** %[parameter][flags][width][.precision][length]type
*/

typedef enum	e_length
{
	none, hh, h, l, ll, j, z, L
}				t_length;

typedef struct	s_flags
{
	int				hashtag;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				single_quote;
	int				i;
}				t_flags;

typedef struct	s_arg
{
	unsigned char	*result;
	int				result_len;
	int				parameter;
	t_flags			flags;
	int				width;
	int				precision;
	t_length		length;
	char			type;
	int				neg_int;
}				t_arg;

typedef	struct	s_data
{
	char			*f; //format string
	va_list			ap;
	unsigned char	*tmp; //tmp string for non arg conversion parts of format
	unsigned char	*s; //final string
	int				byte_count; //length of final string
	int				indicate_param; //are parameter indicators used?
	int				null_char;

}				t_data;

int				ft_printf(const char *format, ...);

void			set_data(t_data *d, char *format);
int				parse_until_arg(t_data *d);
int				parse_arg(t_data *d);
int				init_arg(t_arg *arg);

int				parse_parameter(t_data *d, t_arg *arg);
int				parse_flags(t_data *d, t_arg *arg);
//int				check_percent_sign(t_data *d, t_arg *arg);
int				parse_width(t_data *d, t_arg *arg);
int				parse_precision(t_data *d, t_arg *arg);
int				parse_length(t_data *d, t_arg *arg);
int				parse_type(t_data *d, t_arg *arg);

int				check_type(t_data *d, t_arg *arg);
int				get_char(t_data *d, t_arg *arg);
int				get_string(t_data *d, t_arg *arg);
int				get_int(t_data *d, t_arg *arg);
int				get_unsigned_int(t_data *d, t_arg *arg);
int				get_address(t_data *d, t_arg *arg);
int				get_percent(t_arg *arg);
int				set_byte_count(t_data *data, t_arg *arg);

int				update_result_len(t_arg *arg);
int				check_precision(t_arg *arg);
int				check_flags(t_arg *arg);
int				check_padding(t_arg *arg);
int				check_flags2(t_arg *arg);
int				check_flags3(t_arg *arg);

#endif
