/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 17:00:17 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/06 15:22:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <limits.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	int	i;
	int	y;
	float f;
	unsigned char *s;
	wchar_t c;
	int ret;

	c = 0x20AD;
	s = (unsigned char *)malloc(10);
	s = (unsigned char *)strcpy((char *)s, "12345");
	s[2] += 200;
	y = 32;
	i = 12345678;
	f = 12.34567;
	ret = printf("%s\n", s);
	return (printf("%i\n",ret));
}
