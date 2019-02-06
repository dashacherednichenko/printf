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

//int	ft_hex_low(long long int d, t_flags *f)
//{
//	char	*str;
//	int		i;
//
//	ft_putstr(str = ft_strlowcase(ft_itoa_base(d, 16)));
//	i = ft_strlen(str);
//	f->min = 0;
//	free(str);
//	return (i);
//}

int	ft_hex(long long int d, t_flags *f)
{
	char 	*str;
	char 	*tmp;
	int		i;
	char 	c;

	str = ft_itoa_base(d, 16);
	f->resh == 1? str = ft_strjoinfree("0X", str, 2) : 0;
	i = ft_strlen(str);
	if (f->min == 1)
	{
		f->w = f->w < 0 ? -f->w : f->w;
		f->zr = 0;
	}
	c = f->zr == 1 ? '0' : ' ';
	if (f->w > i)
	{
		tmp = ft_memalloc(f->w-- - i + 1);
		while (f->w - i >=0)
		{
			tmp[f->w-- - i] = c;
		}
		str =  f->min == 1 ? ft_strjoinfree(str, tmp, 3) : ft_strjoinfree(tmp, str, 3);
	}
	str = f->type == 'X' ? str :  ft_strlowcase(str);
	ft_putstr(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}