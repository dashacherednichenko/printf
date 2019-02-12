/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:19:58 by dpiven            #+#    #+#             */
/*   Updated: 2019/02/01 16:19:59 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define TYPE "bcCsSpdDioOuUxXfF%"

int			ft_pars_tp(va_list ar, t_flags *f, int i, char *s)
{
	f->tp = s[i];
	s[i] == 'c' || s[i] == 'C' ? f->l += ft_putcharn((char)va_arg(ar, int), f, 0) : 0;
	s[i] == 's' || s[i] == 'S' ? f->l += ft_putstrn(va_arg(ar, char*), f, 0) : 0;
	s[i] == 'p' ? f->l += ft_ptrtype(va_arg(ar, long long int), f) : 0;
	s[i] == 'd' || s[i] == 'i' || s[i] == 'D' ? f->l += ft_d(ar, f) : 0;
	s[i] == 'b' ? f->l += ft_bin(ar, f) : 0;
	s[i] == 'o' || s[i] == 'O' ? f->l += ft_octal(va_arg(ar, long long int), f) : 0;
	s[i] == 'u' || s[i] == 'U' ? f->l += ft_unsig(va_arg(ar, long long int), f, 0) : 0;
	s[i] == 'X' || s[i] == 'x' ? f->l += ft_hex(va_arg(ar, long long int), f) : 0;
	s[i] == 'f' || s[i] == 'F' ? f->l += ft_float(ar, f) : 0;
	s[i] == '%' ? f->l += ft_percent('%', f) : 0;
	return (f->l);
}

static int	ft_flag_h(t_flags *f, int i, char *s, char c)
{
	if (s[i + 1] == c)
	{
		f->mod = c == 'h' ? "hh" : "ll";
		i++;
	}
	else
		f->mod = c == 'h' ? "h" : "l";
	return (i);
}

int			ft_pars_flag(va_list ar, t_flags *f, int i, char *s)
{
	s[i] == '-' ? f->min = 1 : 0;
	s[i] == ' ' ? f->space = 1 : 0;
	s[i] == '+' ? f->plus = 1 : 0;
	s[i] == '#' ? f->resh = 1 : 0;
	s[i] == '0' && !ft_isdigit(s[i - 1]) ? f->zr = 1 : 0;
	if (s[i] == '*' && f->tchn_t != 1)
	{
		f->w = va_arg(ar, int);
		f->w < 0 ? f->min = 1 : 0;
	}
	s[i] > '0' && s[i] <= '9' ? i = ft_width(s, f, i) : 0;
	s[i] == '.' ? i = ft_precision(s, f, i) : 0;
	if (s[i - 1] == '.' && s[i] == '*' && f->tchn_t == 1)
		f->tchn = va_arg(ar, int);
	s[i] == '#' ? f->resh = 1 : 0;
	s[i] == 'z' ? f->mod = "z" : 0;
	s[i] == 'j' ? f->mod = "j" : 0;
	if (s[i] == 'h' && !f->mod)
		i = ft_flag_h(f, i, s, 'h');
	if (s[i] == 'l')
		i = ft_flag_h(f, i, s, 'l');
	s[i] == 'L' ? f->mod = "L" : 0;
	return (i);
}

int			ft_pars(va_list ar, t_flags *f, int i, char *s)
{
	while (s[i])
	{
		f = ft_obnul_fl(f);
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
		if (s[i] == '%')
		{
			i++;
			while (!ft_strrchr(TYPE, s[i]) && s[i])
			{
				i = ft_pars_flag(ar, f, i, s);
				if (!ft_strrchr("*-+ #0123456789.hlLzj", s[i]))
				{
					f->non_v = s[i];
					break ;
				}
				(!ft_strrchr(TYPE, s[i]) && s[i]) ? i++ : 0;
			}
			s[i] && ft_strrchr(TYPE, s[i]) ?\
				f->l = ft_pars_tp(ar, f, i++, s) : 0;
			if (f->non_v != 0)
				f->l += ft_putcharn(f->non_v, f, i++);
		}
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
	}
	return (f->l);
}
