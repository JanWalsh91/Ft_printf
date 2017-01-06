/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:33:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/06 18:22:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "locale.h"
#define TEST "alkdsii , %010d, %X, %%, %x, %o,123 %C, %s\n", 67, i, i, i, 0x20AD, "abc"
#define TEST1 "1111111111111%c8888", 0x20AD
int	main(void)
{
	int		i;
	//setlocale(LC_ALL, "");

	i = 10;
	//ft_printf("(ft_printf) return value: %i\n", ft_printf(TEST));
	printf("(printf)    return value: %i\n", printf(TEST1));
	return (0);
}
