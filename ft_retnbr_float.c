/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retnbr_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:16:40 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 14:16:42 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long int		ft_calcnbrost(long long int i)
{
	int g;

	g = 10;
	while (i-- > 0)
		g = g * 10;
	return (g);
}

int					ft_calc_nbr(long long int d)
{
	int i;

	i = 1;
//	d < 0 ? d = -d : 0;
	while (d >= 10)
	{
		d = d / 10;
		i++;
	}
	return (i);
}
