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

void	ft_putnbrlln(long long int n, int z)
{
	char					*str;
	unsigned long long int	nb;

	(n < 0) ? (nb = -n) : 1;
	(n < 0) ? z++ : (nb = n);
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
	free(str);
}
