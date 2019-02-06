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

#include "printf.h"

int	ft_d(va_list ar, t_flags *f)
{
	int				i;
	long long int	d;

	d = va_arg(ar, long long int);
	if ((unsigned long long)d == 9223372036854775808U)
	{
		ft_putstr("-9223372036854775808");
		return (ft_strlen("-9223372036854775808"));
	}
	i = ft_putnbrlln(d, f);
	return (i);
}
