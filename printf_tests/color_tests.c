/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:24:41 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/14 16:41:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *s = "\e[27mtest\033[0m";
	int	ret;
	char *a = "\x1B[22;34mThis is a blue text.\e[0m";
	char *b = "This is a blue text.";
	//char *a = "printf test\n";
	
	//write(1, s, ft_strlen(s));
	ret = printf("%s\n", s);
	printf("return value: %i\n", ret);
	return (0);
}
