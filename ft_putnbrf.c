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

int	ft_putnbrf(va_list ar, t_flags *f)
{
	unsigned long long	nb;
	char				*str;
	char				*s1;
	int 				x;
	int 				t;
	long double			ld;
	long double			r;
	long long int		g;
	unsigned long long	n;
	int					z;
	int					minus;

	r = va_arg(ar, long double);
	ld = va_arg(ar, double);
	z = f->tchn == 0 ? 6 : f->tchn;
	g = ft_calcnbrost(z);
//	printf("MINUS %d\n", minus);
//	if (r < 0.0l)
//		r *= -1.0l;
	minus  = ld < 0.0l ? 1 : 0;
//	printf("MINUS %d\n", minus);
//	if (f->type == 'F')
//		minus = ((*(((char*)&r) + 9)) >> 7) ? 1 : 0;
	ld < 0 ? ld = -1 * ld : 0;
	n = (unsigned long long)(ld * g);
	str = ft_memalloc(z-- + 1);
	nb = n;
	x = nb % 10 == 9 ? 1 : 0;
	nb = nb / 10;
	while (z >= 0)
	{
		if (x == 1 && nb % 10 >= 5 && nb % 10 < 9)
		{
			str[z] = nb % 10 + 1 + '0';
			x = 0;
		}
		else if (x == 1 && nb % 10 == 9)
		{
			str[z] = '0';
			x = 1;
		}
		else
		{
			str[z] = nb % 10 + x + '0';
			x = 0;
		}
		nb = nb / 10;
		z--;
	}
	x == 1 ? ld = ld + 1 : 0;
	s1 = ft_itoa_base(ld, 10);
	if (minus == 1)
		s1 = ft_strjoinfree("-", s1, 2);
	if (f->tchn_t == 1 && f->tchn == 0)
		free(str);
	else
	{
		s1 = ft_strjoinfree(s1, ".", 1);
		s1 = ft_strjoinfree(s1, str, 3);
	}
	f->tchn_t = 0;
	f->tchn = 0;
	t = ft_putstrn(s1, f, 0);
	free(s1);
	return (t);
}
