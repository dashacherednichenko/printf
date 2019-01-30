/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obnul_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:25:20 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 16:28:29 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	*ft_obnul_fl(t_flags *fl)
{
	fl->w = 0;
	fl->tchn = 0;
	fl->zr = 0;
	fl->min = 0;
	fl->space = 0;
	fl->plus = 0;
	fl->tchn_t = 0;
	return (fl);
}
