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

void	ft_putnbrf(unsigned long long n, int z)
{
	unsigned long long  nb;
	char			*str;

	str = (char*)malloc(sizeof(char) * (z + 1));
	str[z--] = '\0';
	nb = n;

	while (z >= 0)
	{
		str[z] = nb % 10 + '0';
		nb = nb / 10;
		z--;
	}
	ft_putstr(str);
	free(str);
}
