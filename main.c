/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:06:34 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:06:58 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
//	printf("hello\n");
//	ft_printf("hello\n");
//	char *s = "hello";
	printf("--test 1 %.9s\n", "MY_!");
	ft_printf("mytest 1 %.9s\n", "MY_!");
	printf("--test 2 %c\n", 'N');
	ft_printf("mytest 2 %c\n", 'N');
	printf("--test 3 %.4d\n", -42);
	ft_printf("mytest 3 %.4d\n", 42);
//	printf("--test 4 %p\n", &s);
//	ft_printf("mytest 4 %p\n", &s);
	return (0);
}
