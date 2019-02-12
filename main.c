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

#include "printf.h"
#include <limits.h>

//# define FMT "C_BLU{%-15dC_YLL %s}C_of\n", 123, "some str"
# define FMT "{%f}\n", 48926100000.4
int	main(void)
{
	int res;
	int res1;
	ft_putnbr(res = printf(FMT));
	ft_putchar('\n');
//    ft_putnbr(res = printf("\033[34m{%-15d\033[33m %s}\033[0m\n", 123, "some str"));
//	ft_putchar('\n');
	ft_putnbr(res1 = ft_printf(FMT));
	ft_putchar('\n');
//	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", filename, str);
	system("leaks ft_printf");
	return (0);
}
