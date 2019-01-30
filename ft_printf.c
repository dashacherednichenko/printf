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

#include "libftprintf.h"

int	ft_printf(char *fmt, ...)
{
	int					i;
	char				*str;
	char				*s;
	int					d;
	long long int		g;
	double				a;
	long double			ld;
	int					l;
	t_flags				*fl;
	va_list				arg;

	va_start(arg, fmt);
	fl = (t_flags*)malloc(sizeof(t_flags));
	i = 0;
	s = fmt;
	while (s[i])
	{
		fl = ft_obnul_fl(fl);
		while (s[i] != '%' && s[i])
		{
			ft_putchar(s[i++]);
			fl->len = i;
		}
		s[i] == '%' ? i++ : i;
		while (!(ft_strrchr("cspdiouxXf", s[i])) && s[i])
		{
			s[i] == '-' ? fl->min = 1 : 0;
			s[i] == ' ' ? fl->space = 1 : 0;
			s[i] == '+' ? fl->plus = 1 : 0;
			(s[i] == '0' && !ft_isdigit(s[i - 1])) ? fl->zr = 1 : 0;
			if (s[i] > '0' && s[i] <= '9')
			{
				(fl->w == 0) ? (fl->w = ft_atoi(&s[i])) : 0;
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == '.')
			{
				fl->tchn_t = 1;
				fl->tchn = ft_atoi(&s[++i]);
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == 'h')
				fl->mod = s[++i] == 'h' ? "hh" : "h";
			if (s[i] == 'l')
				fl->mod = s[++i] == 'l' ? "ll" : "l";
			s[i] == 'L' ? fl->mod = "L" : 0;
			(!(ft_strrchr("cspdiouxXf", s[i])) && s[i]) ? i++ : i;
		}
		if (s[i] == 'c')
		{
			fl->len += ft_putcharn((char)va_arg(arg, int), fl);
			i++;
		}
		else if (s[i] == 's')
		{
			str = va_arg(arg, char*);
			!str ? str = "(null)" : 0;
			fl->len += ft_putstrn(str, fl);
			i++;
		}
		else if (s[i] == 'p')
		{
			fl->len += ft_ptrtype(va_arg(arg, long long int), fl);
			i++;
		}
		else if (s[i] == 'd' || s[i] == 'i')
		{
			if (fl->mod && !ft_strcmp(fl->mod, "l"))
			{
				g = va_arg(arg, long long int);
				!fl->tchn ? ft_putnbrll(g) : ft_putnbrlln(g, fl->tchn);
				i++;
			}
			else
			{
				d = va_arg(arg, long long int);
				!fl->tchn ? ft_putnbr(d) : ft_putnbrn(d, fl->tchn, fl->w);
			}
			i++;
		}
		else if (s[i] == 'o')
		{
			ft_putstr(str = ft_itoa_base(va_arg(arg, long long int), 8));
			free(str);
			i++;
		}
		else if (s[i] == 'u')
		{
			ft_putstr(str = ft_itoa_base(va_arg(arg, long long int), 10));
			free(str);
			i++;
		}
		else if (s[i] == 'x')
		{
			d = va_arg(arg, long long int);
			ft_putstr(str = ft_strlowcase(ft_itoa_base(d, 16)));
			free(str);
			i++;
		}
		else if (s[i] == 'X')
		{
			ft_putstr(str = ft_itoa_base(va_arg(arg, long long int), 16));
			free(str);
			i++;
		}
		else if (s[i] == 'f')
		{
			if (fl->mod && !ft_strcmp(fl->mod, "L"))
			{
				ft_putnbrll(ld = va_arg(arg, long double));
				ft_putchar('.');
				fl->tchn == 0 ? fl->tchn = 6 : 0;
				g = ft_calcnbrost(fl->tchn);
				ld < 0 ? ld = -1 * ld : 0;
				ft_putnbrf((unsigned long long)(ld * g), fl->tchn);
			}
			else
			{
				ft_putnbrll(a = va_arg(arg, double));
				ft_putchar('.');
				fl->tchn == 0 ? fl->tchn = 6 : 0;
				g = ft_calcnbrost(fl->tchn);
				a < 0 ? a = -1 * a : 0;
				ft_putnbrf((unsigned long long)(a * g), fl->tchn);
			}
			i++;
		}
		if (!s[i])
			break ;
//		i++;
//		s[i + 1] ? i++ : i;
		while (s[i] != '%' && s[i])
		{
			fl->len++;
			ft_putchar(s[i++]);
		}
	}
	va_end(arg);
	l = fl->len;
	free(fl);
	return (l);
}
