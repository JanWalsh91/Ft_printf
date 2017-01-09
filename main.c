/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:33:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/09 14:36:02 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#define TEST0 "alkdsii , %010d, %X, %%, %x, %o,123 %C, %s\n", 67, i, i, i, 0x20AD, "abc"
#define TEST1 "1111111111111%C8888", 0x20AD
#define TEST3 "simple test:%i\n", 90
#define TEST4 "k"
#define TEST5 "hello: %n", &i
#define TEST6 "adsfj"
#define TEST7 "abcd %i\n", y
#define TEST8 "%0 +'9.ll%\n"
#define TEST9 "%x", -42
#define TEST10
#define TEST11
#define TEST12
#define TEST13
#define TEST14
#define TEST15
#define TEST16
#define TEST17
#define TEST18
#define TEST19

#define TEST TEST9

int	main(void)
{
	int		i, y;
	setlocale(LC_ALL, "");

	y = 1123509;
	i = 10;
	printf("(ft_printf) return value: %i\n", ft_printf(TEST));
	printf("(printf)    return value: %i\n", printf(TEST));
	return (0);
}
