/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:33:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/13 14:35:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
#include <limits.h>

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
#define TEST29 "{%i, % -.9}iiiii", 90
#define TEST30 "%C", L'猫'
#define TEST31 "%C", L'δ'
#define TEST32 "%C", L'요'
#define TEST33 "%C", L'莨'
#define TEST34 "%C", L'ي'
#define TEST35 "%C", 0
#define TEST36 "{%}"
#define TEST37 "% Zooo"
#define TEST38 "%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ", L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""
#define TEST39 "%S", NULL
#define TEST40 "%C ll%c", 0, 'a'
#define TEST50 "%llU, %llU", 0, USHRT_MAX
#define TEST51 "%hhO, %hhO", 0, USHRT_MAX
#define TEST52 "%hhC, %hhC", 0, L'米'
#define TEST53 "%hhS, %hhS", 0, L"米米"
#define TEST54 "%S", s
#define TEST55 "%S", L"米米"
#define TEST56 "%S", L"Τ τ"
#define TEST57 "%C", L'ي'
#define TEST58 "{%3c}", 0
#define TEST59 "{%2R}"
#define TEST60 "{%-15ZZ}", 123
#define TEST61 "%#o", 0
#define TEST62 "%#.O", 0
#define TEST63 "%.o, %0.o", 0, 0 
#define TEST64 "#o: %#o #.o: %#.0o o: %o o.: %.0o", 0, 0, 0, 0
#define TEST65 "%0"
#define TEST66 "%.4S", L"我是一只猫。"
#define TEST67 "%10S", L"我"
#define TEST68 "{%05.c}", 'o'
#define TEST69
#define TEST70

#define TEST TEST57

int	main(void)
{
	int		i, y;
	setlocale(LC_ALL, "");

	char *s= (char *)strdup("1234567890");
	s[5] = 0;
	y = 1123509;
	i = 10;
	//printf("USHRTMAX: %O\n", USHRT_MAX);
	printf(":(printf)    return value:%i\n", printf(TEST));
	printf(":(ft_printf) return value:%i\n", ft_printf(TEST));
	//printf(":(printf)    return value:%i", printf(TEST));
	//printf(":(ft_printf) return value:%i", ft_printf(TEST));
	return (0);
}
