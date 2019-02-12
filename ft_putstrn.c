/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:55:12 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/03 12:55:15 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printnbr(char *s)
{
	int z;

	z = 0;
	while (s[z])
		ft_putchar(s[z++]);
	free(s);
	return (z);
}

int			ft_putstrn(char *str, t_flags *f, int i)
{
	char	*newstr;
	int		t;
	int		w;

	f->tp == 'S' ? f->mod = "l" : 0;
	!str ? str = "(null)" : 0;
	t = ft_strlen(str);
	if (f->tchn == 0 && f->w == 0 && f->tchn_t == 1)
		return (i);
	(f->tchn < 0) ? f->tchn = t : 0;
	(f->min == 1 && f->w >= 0) ? f->w = -f->w : 0;
	w = f->w < 0 ? f->w : 0;
	((!f->w || f->w < f->tchn) && f->tchn < t) ? f->w = f->tchn : 0;
	(!f->w || (f->w < t && (f->tchn > t || !f->tchn_t))) ? f->w = t : 0;
	newstr = ft_memalloc((f->w--) + 1);
	(!f->tchn_t || f->tchn >= t) ? f->tchn = t : 0;
	while (str[i] && i < f->tchn)
		newstr[f->w--] = str[(t - (t + 1 - f->tchn)) - i++];
	while (f->w >= 0 && i++ >= 0)
		newstr[f->w--] = (f->zr == 1 ? '0' : ' ');
	ft_putstr(newstr);
	while ((w + i++) < 0)
		ft_putchar(' ');
	free(newstr);
	return (i - 1);
}
