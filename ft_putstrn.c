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
	int		tmp;

	i = 0;
	t = ft_strlen(str);
	tmp = t--;
	((!f->w || f->w < f->tchn) && f->tchn < tmp) ? f->w = f->tchn : 0;
	(!f->w || (f->w < tmp && (f->tchn > tmp || !f->tchn_t))) ? f->w = tmp : 0;
	newstr = ft_memalloc((f->w--) + 1);
	(!f->tchn_t || f->tchn >= t) ? f->tchn = tmp : 0;
	while (str[i] && i < f->tchn)
	{
		newstr[f->w--] = str[((t--) - (tmp - f->tchn))];
		i++;
	}
	while (f->w >= 0)
	{
		newstr[f->w--] = (f->zr == 1 ? '0' : ' ');
		i++;
	}
	ft_putstr(newstr);
	free(newstr);
	return (i);
}
