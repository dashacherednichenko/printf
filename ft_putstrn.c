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

#include "libftprintf.h"

int	ft_putstrn(char *str, t_flags *f)
{
	char	*newstr;
	int		i;
	int		t;
	int		w;

	!str ? str = "(null)" : 0;
	i = 0;
	t = ft_strlen(str);
//	f->tchn_t == 1
//printf("tch %d\n", f->tchn);
//	printf("1w %d\n", f->w);
	(f->tchn < 0) ? f->w = f->tchn : 0;
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
	while ((w + i) < 0)
	{
		ft_putchar(' ');
		i++;
	}
	free(newstr);
	return (i);
}
