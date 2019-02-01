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

#include "libftprintf.h"

int	ft_pars_type(va_list ar, t_flags *f, int i, char *s)
{
	s[i] == 'c' ? f->l += ft_putcharn((char)va_arg(ar, int), f) : 0;
	s[i] == 's' ? f->l += ft_putstrn(va_arg(ar, char*), f) : 0;
	s[i] == 'p' ? f->l += ft_ptrtype(va_arg(ar, long long int), f) : 0;
	s[i] == 'd' || s[i] == 'i' ? f->l += ft_d(ar, f) : 0;
	s[i] == 'o' ? f->l += ft_octal(va_arg(ar, long long int), f) : 0;
	s[i] == 'u' ? f->l += ft_unsig(va_arg(ar, long long int), f) : 0;
	s[i] == 'x' ? f->l += ft_hex_low(va_arg(ar, long long int), f) : 0;
	s[i] == 'X' ? f->l += ft_hex(va_arg(ar, long long int), f) : 0;
	s[i] == 'f' ? f->l += ft_float(ar, f) : 0;
	return (f->l);
}

int	ft_pars(va_list ar, t_flags *f, int i, char *s)
{
	while (s[i])
	{
		f = ft_obnul_fl(f);
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
		s[i] == '%' ? i++ : i;
		while (!ft_strrchr("cspdiouxXf", s[i]) && s[i])
		{
			s[i] == '-' ? f->min = 1 : 0;
			s[i] == ' ' ? f->space = 1 : 0;
			s[i] == '+' ? f->plus = 1 : 0;
			s[i] == '0' && !ft_isdigit(s[i - 1]) ? f->zr = 1 : 0;
			s[i] > '0' && s[i] <= '9' ? i = ft_width(s, f, i) : 0;
			s[i] == '.' ? i = ft_precision(s, f, i) : 0;
			if (s[i] == 'h')
				f->mod = s[++i] == 'h' ? "hh" : "h";
			if (s[i] == 'l')
				f->mod = s[++i] == 'l' ? "ll" : "l";
			s[i] == 'L' ? f->mod = "L" : 0;
			(!ft_strrchr("cspdiouxXf", s[i]) && s[i]) ? i++ : 0;
		}
		ft_strrchr("cspdiouxXf", s[i]) ? f->l = ft_pars_type(ar, f, i++, s) : 0;
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
	}
	return (f->l);
}
