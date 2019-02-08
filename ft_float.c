/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:56:19 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 15:56:20 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_float(va_list ar, t_flags *f)
{
	int					i;
	long long int		g;
	double				a;
	long double			ld;

	i = 0;
	if (f->mod && !ft_strcmp(f->mod, "L"))
	{
		i = ft_putnbrll(ld = va_arg(ar, long double), 0);
		ft_putchar('.');
		i++;
		f->tchn == 0 ? f->tchn = 6 : 0;
		g = ft_calcnbrost(f->tchn);
		ld < 0 ? ld = -1 * ld : 0;
		i += ft_putnbrf((unsigned long long)(ld * g), f->tchn);
	}
	else
	{
		i = ft_putnbrll(a = va_arg(ar, double), 0);
		ft_putchar('.');
		i++;
		f->tchn == 0 ? f->tchn = 6 : 0;
		g = ft_calcnbrost(f->tchn);
		a < 0 ? a = -1 * a : 0;
		i += ft_putnbrf((unsigned long long)(a * g), f->tchn);
	}
	return (i);
}
