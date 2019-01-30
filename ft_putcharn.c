/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:52:06 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 14:52:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putcharn(char c, t_flags *flags)
{
	int i;
	int w;
	int z;

	i = 1;
	w = flags->w;
	z = flags->zr;
	while (i < w)
	{
		z == 1 ? ft_putchar('0') : ft_putchar(' ');
		i++;
	}
	ft_putchar(c);
	return (i);
}
