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

int	ft_putstrn(char *str, int n, int w)
{
	char	*newstr;
	int		i;
	int		t;
	int		tmp;

	i = 0;
	t = ft_strlen(str);
	tmp = t;
	((w == 0 && n < tmp) || ((w < n) && (n < tmp))) ? w = n : w;
	(w == 0 || (w < tmp && n > tmp)) ? w = tmp : w;
	newstr = ft_memalloc((w--) + 1);
	(n == 0 || n >= (t--)) ? n = tmp : n;
	while (str[i] && i < n)
	{
		newstr[w--] = str[((t--) - (tmp - n))];
		i++;
	}
	while (w >= 0)
	{
		newstr[w--] = ' ';
		i++;
	}
	ft_putstr(newstr);
	free(newstr);
	return (i);
}
