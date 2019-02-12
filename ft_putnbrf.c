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

#include "printf.h"

int	ft_putnbrf(unsigned long long n, long long int z)
{
	unsigned long long	nb;
	char				*str;
	int					i;
	int					ii;
	int 				x;

	str = (char*)malloc(sizeof(char) * (z + 1));
	str[z--] = '\0';
	nb = n;
	ii = 0;
	i = nb % 10;
	nb = nb / 10;
	while (z >= 0)
	{
		str[z] = nb % 10 + '0';
		if (ii == 0 && i >= 5 && i < 9)
		{
			str[z] = nb % 10 + 1 + '0';
			ii++;
		}
//		else if (ii == 0 && i == 9)
//		{
//			str[z--] = '0';
//			nb = nb / 10;
//			nb % 10 != 9 ? str[z] = nb % 10 + 1 + '0' : '0';
//			ii++;
//		}
		nb = nb / 10;
		z--;
	}
	ft_putstr(str);
	x = ft_strlen(str);
	free(str);
	return(x);
}
