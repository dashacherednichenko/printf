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

# include "libftprintf.h"

void	ft_putnbrn(int n, int z)
{
	unsigned int nb;
	int i;

	i = 1;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (i <= z)
	{
		ft_putchar('0');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		i++;
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
}
