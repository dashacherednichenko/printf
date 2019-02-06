/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:32:29 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:32:30 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//int ft_valid_type(char *s, int i)
//{
//	while (s[i] && s[i] != '%')
//		i++;
//	if (s[i] == '%')
//		i++;
//	while (s[i])
//	{
//		if (ft_strrchr("cspdDiouUxXf", s[i]))
//			return (1);
//		i++;
//	}
//	return (0);
//}

int	ft_printf(char *fmt, ...)
{
	int					i;
	char				*s;
//	int					x;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	i = 0;
	s = fmt;
	f->l = 0;
//	x = ft_valid_type(s , i);
//	if (x == 0)
//	{
//		i = ft_print_txt(s, f, i);
//		s[i] == '%' ? i++ : i;
//		return (ft_print_txt(s, f, i) - 1);
//	}
//	else
		f->l = ft_pars(ar, f, i, s);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}
