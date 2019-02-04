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

//void	ft_putnbrn(int n, int z, int w)
//{
//	char			*str;
//	unsigned int	nb;
//	int t;
//
//	(n < 0) ? (nb = -n) : 1;
//	(n < 0) ? z++ : (nb = n);
//	t = z;
//	w > z ? t = w : t;
//	str = (char*)malloc(sizeof(char) * (t + 1));
//	str[t--] = '\0';
//	z--;
//	w--;
//	while (nb >= 10)
//	{
//		str[t--] = (nb % 10 + '0');
//		z--;
//		w--;
//		nb = nb / 10;
//	}
//	str[t--] = nb + '0';
//	z--;
//	w--;
//	if (n >= 0)
//	{
//		while (z-- >= 0)
//		{
//			str[t--] = '0';
//			w--;
//		}
//	}
//	else
//	{
//		while (z-- > 0)
//		{
//			str[t--] = '0';
//			w--;
//		}
//		str[t--] = '-';
//		w--;
//	}
//	if (t >= 0)
//		while (t >= 0)
//			str[t--] = ' ';
//	ft_putstr(str);
//	free(str);
//}
