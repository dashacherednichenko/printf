/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:53:08 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 16:53:09 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strtemp(int x, int i, char c)
{
	char *tmp2;

	tmp2 = ft_memalloc(x-- - i + 1);
	while (x - i >= 0)
		tmp2[x-- - i] = c;
	return (tmp2);
}

int		ft_ptrtype(long long int d, t_flags *fl)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strlowcase(ft_itoa_base(d, 16));
	if (fl->tchn > (i = ft_strlen(tmp)))
	{
		tmp2 = ft_strtemp(fl->tchn, i, '0');
		tmp = ft_strjoinfree(tmp2, tmp, 3);
	}
	if (fl->zr == 1 && !fl->tchn_t && fl->w > i + 2)
	{
		tmp2 = ft_strtemp(fl->w, i + 2, '0');
		tmp = ft_strjoinfree(tmp2, tmp, 3);
	}
	tmp = ft_strjoinfree("0x", tmp, 2);
	i = ft_strlen(tmp);
	if (fl->w > i)
	{
		tmp2 = ft_strtemp(fl->w, i, ' ');
		tmp = ft_strjoinfree(tmp2, tmp, 3);
	}
	i = ft_putstrn(tmp, ft_obnul_fl(fl));
	free(tmp);
	return (i);
}
