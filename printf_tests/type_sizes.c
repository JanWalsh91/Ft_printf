/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:15:42 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/30 16:39:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int	main(void)
{
	printf("char: %li\n", sizeof(char));
	printf("short: %li\n", sizeof(short));
	printf("int: %li\n", sizeof(int));
	printf("wchar_t: %li\n", sizeof(wchar_t));
	printf("wint_t: %li\n", sizeof(wint_t));
	printf("size_t: %li\n", sizeof(size_t));
	printf("long: %li\n", sizeof(long));
	printf("long long: %li\n", sizeof(long long));
	printf("intmax_t: %li\n", sizeof(intmax_t));
	printf("uintmax_t: %li\n", sizeof(uintmax_t));
	printf("float: %li\n", sizeof(float));
	printf("double: %li\n", sizeof(double));
	printf("long double: %li\n", sizeof(long double));

	unsigned char c;

	c = 130;
	printf("%hhi\n", c);
	return (0);
}
