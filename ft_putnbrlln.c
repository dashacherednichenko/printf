/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:32:57 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/03 14:33:02 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbrlln(long long int n, t_flags *f)
{
	char					*str;
	unsigned long long int	nb;
	int						z;
	int						i;

//	i = ft_calc_nbr(n);
//	printf("IIII%d\n", i);
	z = f->tchn;

//	printf("\n%d\n\n", ft_calc_nbr(n));
if (n < 0)
	nb = n * (-1);
else
	nb = n;
//	nb = n < 0 ? (-1*n) : n;
	printf("IIII%d\n", nb);
	i = ft_calc_nbr(nb);
	printf("IIII%d\n", i);
	z < i ? z = i : 0;
	n < 0 ? z++ : 0;
	str = (char*)malloc(sizeof(char) * (z + 1));
	str[z--] = '\0';
	while (nb >= 10)
	{
		str[z--] = (nb % 10 + '0');
		nb = nb / 10;
	}
	str[z--] = nb + '0';
	if (n >= 0)
		while (z >= 0)
			str[z--] = '0';
	else
	{
		while (z > 0)
			str[z--] = '0';
		str[z] = '-';
	}
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
