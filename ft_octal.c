/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:31:51 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 14:31:52 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_octal(long long int d, t_flags *f)
{
	char	*str;
	int		i;

	ft_putstr(str = ft_itoa_base(d, 8));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}

int	ft_unsig(long long int d, t_flags *f)
{
	char	*str;
	int		i;

	ft_putstr(str = ft_itoa_base(d, 10));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}

int	ft_hex(long long int d, t_flags *f)
{
	char	*s;
	char	*tmp;
	int		i;

	s = ft_itoa_base(d, 16);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	i = ft_strlen(s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = ft_strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = ft_strjoinfree(tmp, s, 3) : 0;
	f->resh == 1 && d != 0 && !f->zr ? s = ft_strjoinfree("0X", s, 2) : 0;
	i = ft_strlen(s);
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	if (f->w > i)
	{
		tmp = f->zr == 1 ? ft_strtemp(f->w, i, '0') : ft_strtemp(f->w, i, ' ');
		s = f->min == 1 ? ft_strjoinfree(s, tmp, 3) : ft_strjoinfree(tmp, s, 3);
		f->resh == 1 && d != 0 && f->zr == 1 ? s[1] = 'X' : 0;
	}
	s = f->type == 'X' ? s : ft_strlowcase(s);
	return (ft_printnbr(s));
}
