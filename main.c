/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:33:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/11 16:50:10 by jwalsh           ###   ########.fr       */
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
#define TEST10 "%#8x", 0
#define TEST11 "%0'+8d", 1234
#define TEST12 "@moulitest: %#.x %#.0x", 0, 0
#define TEST13 "@moulitest: %#.o %#.0o", 0, 0
#define TEST14 "null:%s\n", NULL
#define TEST15 "@moulitest: %s", NULL
#define TEST16 "%.2c", NULL
#define TEST17 "% d", -42
#define TEST18 "%d", 42
#define TEST19 "%c", NULL
#define TEST20 "%2c", 0
#define TEST21 "%d", 2147483648
#define TEST22 "%lld", -9223372036854775808
#define TEST23 "%U", "4294967295"
#define TEST24 "%jx", 4294967295
#define TEST25 "@moulitest: %.d %.0d", 0, 43
#define TEST26 "%hU", 4294967296
#define TEST27 "%p", NULL
#define TEST28 "%#o", 0
#define TEST29 "{%i, % -l.9}iiiii%s", 90, "hoh"
#define TEST30 "%C", L'猫'
#define TEST31 "%C", L'δ'
#define TEST32 "%C", L'요'
#define TEST33 "%C", L'莨'
#define TEST34 "%C", L'ي'
#define TEST35 "%C", 0
#define TEST36 "@moulitest: %#.o %#.0o", 9, 0
#define TEST37
#define TEST38
#define TEST39
#define TEST40

#define TEST TEST36

int	main(void)
{
	int		i, y;
	setlocale(LC_ALL, "");

	y = 1123509;
	i = 10;
	printf(":(printf)    return value:%i\n", printf(TEST));
	printf(":(ft_printf) return value:%i\n", ft_printf(TEST));
	//printf(":(printf)    return value:%i", printf(TEST));
	//printf(":(ft_printf) return value:%i", ft_printf(TEST));
	return (0);
}
