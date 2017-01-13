/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:53:24 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/13 14:03:31 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "unistd.h"
#include <wchar.h>
#include <stdio.h>

int	main(void)
{
	wchar_t a = L'猫';
	int ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0, ret5 = 0;
	UC * b= ft_wctostr(a);

	ret1 = write(1, b++, 1);
	ret2 = write(1, b++, 1);
	ret3 = write(1, b++, 1);
	ret4 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);
	ret5 = write(1, b++, 1);





	printf("\n1: %i 2: %i 3: %i 4: %i 5: %i\n", ret1, ret2, ret3, ret4, ret5);
	return (0);
}
