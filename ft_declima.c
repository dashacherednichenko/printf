/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declima.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:39:54 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 15:39:55 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_d(va_list ar, t_flags *f)
{
	int				i;
	long long int	d;

	d = va_arg(ar, long long int);
	f->mod && !ft_strcmp(f->mod, "h") ? d = (short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (char)d : 0;
	if (f->mod && !ft_strcmp(f->mod, "ll"))
	{
		!f->tchn ? ft_putnbrll(d) : ft_putnbrlln(d, f->tchn);
		i++;
	}
	else
		!f->tchn ? ft_putnbr(d) : ft_putnbrn(d, f->tchn, f->w);
	return (i);
}
