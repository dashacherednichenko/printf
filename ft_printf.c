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
	int i;
	long long int n;
	char *str;
	char *s;
	char *tmp;
	char c;
	int d;
	long long g;
	unsigned long long f;
	long long int ptr;
	double a;
	int ii;
	long double ld;
	int w;
	t_flags *flags;

	va_list arg;
	va_start(arg, fmt);

	w = 0;
	flags = (t_flags*)malloc(sizeof(t_flags));
	i = 0;
	s = fmt;
	while (s[i])
	{
		n = 0;
		while (s[i] != '%' && s[i])
		{
			ft_putchar(s[i++]);
			flags->length = i;
		}
		if (s[i] == '%')
			i++;
		else
			break;
		while (!(ft_strrchr("cspdiouxXf", s[i])) && s[i])
		{
			s[i] == '-' ? flags->min = 1 : i;
			s[i] == ' ' ? flags->space = 1 : i;
			s[i] == '+' ? flags->plus = 1 : i;
			(s[i] == '0' && s[i - 1] < '0' && s[i - 1] > '9') ? flags->zero = 1 : i;
//			s[i] > '0' && s[i] <= '9' ? flags->width = ft_atoi(&s[i]) : i;
			if (s[i] > '0' && s[i] <= '9')
			{
				w = ft_atoi(&s[i]);
				w == 0 ? flags->width = w : i;
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == '.')
			{
				n = ft_atoi(&s[++i]);
				flags->precision = n;
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == 'h')
			{
				if (s[++i] != 'h')
				{
					flags->mod =(char*)malloc(sizeof(char) * (1 + 1));
					flags->mod = "h";
				}
				else
				{
					flags->mod =(char*)malloc(sizeof(char) * (2 + 1));
					flags->mod = "hh";
					i++;
				}
			}
			if (s[i] == 'l')
			{
				if (s[++i] != 'l')
				{
					flags->mod =(char*)malloc(sizeof(char) * (1 + 1));
					flags->mod = "l";
				}
				else
				{
					flags->mod =(char*)malloc(sizeof(char) * (2 + 1));
					flags->mod = "ll";
					i++;
				}
			}
			if (s[i] == 'L')
			{
				flags->mod =(char*)malloc(sizeof(char) * (1 + 1));
				flags->mod = "L";
				i++;
			}
		}
		if (s[i] == 'c')
		{
			c = (char)va_arg(arg, int);
			ft_putchar(c);
			flags->length++;
		}
		else if (s[i] == 's')
		{
			str = va_arg(arg, char*);
			if (str == 0)
				str = "(null)";
			flags->length = flags->length + ft_putstrn(str, flags->precision);
		}
		else if (s[i] == 'p')
		{
			ptr = va_arg(arg, long long int);
			tmp = ft_strlowcase(ft_itoa_base(ptr, 16));
			str = ft_strjoin("0x", tmp);
			ft_putstr(str);
			free(str);
			free(tmp);
		}
		else if (s[i] == 'd' || s[i] == 'i')
		{
			if (flags->mod != 0 && (ft_strcmp(flags->mod,"l") == 0 || ft_strcmp(flags->mod, "ll") == 0))
			{
				g = va_arg(arg, long long int);
				n == 0 ? ft_putnbrll(g) : ft_putnbrlln(g, n);
				i++;
			}
			else
			{
				d = va_arg(arg, long long int);
				n == 0 ? ft_putnbr(d) : ft_putnbrn(d, flags->precision, w);
			}
		}
		else if (s[i] == 'o')
		{
			d = va_arg(arg, long long int);
			str = ft_itoa_base(d, 8);
			ft_putstr(str);
			free(str);
		}
		else if (s[i] == 'u')
		{
			d = va_arg(arg, long long int);
			str = ft_itoa_base(d, 10);
			ft_putstr(str);
			free(str);
		}
		else if (s[i] == 'x')
		{
			d = va_arg(arg, long long int);
			str = ft_strlowcase(ft_itoa_base(d, 16));
			ft_putstr(str);
			free(str);
		}
		else if (s[i] == 'X')
		{
			d = va_arg(arg, long long int);
			str = ft_itoa_base(d, 16);
			ft_putstr(str);
			free(str);
		}
		else if (s[i] == 'f')
		{
			if (flags->mod && ft_strcmp(flags->mod, "L") == 0)
			{
				ld = va_arg(arg, long double);
				ft_putnbrll(ld);
				ft_putchar('.');
				n == 0 ? n = 6 : n;
				ii = n;
				g = 10;
				while (ii-- > 0)
					g = g * 10;
				if (ld < 0)
					f = ld * (-g);
				else
					f = ld * g;
				ft_putnbrf(f, n);
			}
			else
			{
				a = va_arg(arg, double);
				ft_putnbrll(a);
				ft_putchar('.');
				n == 0? n = 6 : n;
				ii = n;
				g = 10;
				while (ii-- > 0)
					g = g * 10;
				a < 0 ? (f = (a * (-g))) : (f = (a * g));
				ft_putnbrf(f, n);
			}

		}
		if (!s[i])
			break;
		s[i + 1] ? i++ : i;
		while (s[i] != '%' && s[i])
		{
			flags->length++;
			ft_putchar(s[i++]);
		}
//		if (!s[i])
//			break;
	}
	va_end (arg);
//	if (flags->mod)
//		free(flags->mod);
//	free(flags);
	return (flags->length);
}