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

int	ft_pars_type(va_list ar, t_flags *f, int i, char *s)
{
	f->type = s[i];
	s[i] == 'c' || s[i] == 'C' ? f->l += ft_putcharn((char)va_arg(ar, int), f) : 0;
	s[i] == 's' || s[i] == 'S' ? f->l += ft_putstrn(va_arg(ar, char*), f) : 0;
	s[i] == 'p' ? f->l += ft_ptrtype(va_arg(ar, long long int), f) : 0;
	s[i] == 'd' || s[i] == 'i' || s[i] == 'D' ? f->l += ft_d(ar, f) : 0;
	s[i] == 'b' ? f->l += ft_bin(ar, f) : 0;
	s[i] == 'o' || s[i] == 'O' ? f->l += ft_octal(va_arg(ar, long long int), f) : 0;
	s[i] == 'u' || s[i] == 'U' ? f->l += ft_unsig(va_arg(ar, long long int), f) : 0;
	s[i] == 'X' || s[i] == 'x' ? f->l += ft_hex(va_arg(ar, long long int), f) : 0;
	s[i] == 'f' || s[i] == 'F' ? f->l += ft_float(ar, f) : 0;
	s[i] == '%' ? f->l += ft_percent('%', f) : 0;
	return (f->l);
}

int ft_valid_type(char *s, int i)
{
	while (s[i])
	{
		if (ft_strrchr("bcCsSpdDioOuUxXfF%", s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_pars(va_list ar, t_flags *f, int i, char *s)
{
	while (s[i])
	{
		f = ft_obnul_fl(f);
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
		s[i] == '%' ? i++ : i;
		if (s[i - 1] == '%' && ft_valid_type(s , i) == 0)
		{
			while (s[i])
			{
				if (ft_strrchr("bcCsSpdDioOuUxXfF%-+ #0123456789.hlLzj", s[i]))
					i++;
				else
				{
					ft_putchar(s[i++]);
					f->l++;
					while (s[i])
					{
						ft_putchar(s[i++]);
						f->l++;
					}
				}
			}
			return (f->l);
		}
		while (!ft_strrchr("bcCsSpdDioOuUxXfF%", s[i]) && s[i])
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
			if (s[i - 1] == '.' && s[i] == '*'  && f->tchn_t == 1)
			{
				f->tchn = va_arg(ar, int);
//				f->tchn < 0 ? f->min = 1 : 0;
			}
			s[i] == '#' ? f->resh = 1 : 0;
			if (s[i] == 'h' && !f->mod)
				f->mod = s[++i] == 'h' ? "hh" : "h";
			s[i] == 'z' ? f->mod = "z" : 0;
			s[i] == 'j' ? f->mod = "j" : 0;
			if (s[i] == 'l')
				f->mod = s[++i] == 'l' ? "ll" : "l";
			s[i] == 'L' ? f->mod = "L" : 0;
 			(!ft_strrchr("bcCsSpdDioOuUxXfF%", s[i]) && s[i]) ? i++ : 0;
		}
		if (s[i])
			ft_strrchr("bcCsSpdDioOuUxXfF%", s[i]) ? f->l = ft_pars_type(ar, f, i++, s) : 0;
		s[i] != '%' && s[i] ? i = ft_print_txt(s, f, i) : 0;
	}
	return (f->l);
}
