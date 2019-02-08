/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:57:52 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/08 14:57:53 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_bin(va_list ar, t_flags *f)
{
	int				i;
	int				ii;
	int 			j;
	int 			ji;
	char			*s;
	long long int	d;
	char 			*tmp;

	j = 32;
	d = va_arg(ar, long long int);
	if (f->mod && !ft_strcmp(f->mod, "h"))
		j = 16;
	else if (f->mod && !ft_strcmp(f->mod, "hh"))
		j = 8;
	else if (f->mod && !ft_strcmp(f->mod, "l"))
		j = 32;
	else if (f->mod && !ft_strcmp(f->mod, "ll"))
		j = 64;
	else if (f->mod && !ft_strcmp(f->mod, "L"))
	{
		j = 80;
		d = va_arg(ar, long double);
//		s = ft_uitoa_base((long double)d, 2);
	}
	ji = j;

	tmp = ft_memalloc(j-- + 1);
	s = ft_uitoa_base(d, 2);
	i = ft_strlen(s);
	ii = i - 1;
	if (f->plus == 1)
		f->zr = 1;
	if (f->zr == 1)
	{
		while (j >= 0)
			tmp[j--] = '0';
		ji--;
		while (ii >= 0)
			tmp[ji--] = s[ii--];
		free(s);
		s = tmp;
	}
	i = 0;
	ii = 0;
	while (s[ii])
	{
		ft_putchar(s[ii++]);
		if (f->plus == 1 && ii % 8 == 0 && s[ii])
		{
			ft_putchar(' ');
			i++;
		}
		i++;
	}
	free(s);
//	free(tmp);
	return (i);
};
