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

void	ft_printf(char *fmt, ...)
{
	int i;
	long long int n;
	char *str;
	char *s;
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

	w = 0;
//	int plus;

//	plus = 0;
	flags = (t_flags*)malloc(sizeof(t_flags));
//	char *p;
	va_list arg;
	va_start(arg, fmt);

	i = -1;
	s = fmt;
	while (s[i])
	{
		n = 0;
		while (s[i++] != '%')
			ft_putchar(s[i]);
//		i++;
		while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != 'f')
		{
//			s[i] == '-' ? flags->min = 1 : i;

			if (s[i] == '-')
			{
				flags->min = 1;
				i++;
			}
			if (s[i] == ' ')
			{
				flags->space = 1;
				i++;
			}
			if (s[i] == '+')
			{
				flags->plus = 1;
				i++;
			}
			if (s[i] > '0' && s[i] <= '9')
			{
				w = ft_atoi(&s[i]);
				flags->width = w;
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == '.')
			{
				i++;
				n = ft_atoi(&s[i]);
				flags->precision = n;
				while (s[i] >= '0' && s[i] <= '9')
					i++;
			}
			if (s[i] == 'h' && s[++i] == 'h')
			{
				i++;
			}
			if (s[i] == 'l' && s[++i] == 'l')
			{
				i++;
				if (s[i] == 'd' || s[i] == 'i')
				{
					g = va_arg(arg, long long int);
					n == 0 ? ft_putnbrll(g) : ft_putnbrlln(g, n);
					i++;
				}
			}
			if (s[i] == 'L')
			{
				if (s[++i] == 'f')
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
					i++;
				}
			}
//			i++;
		}
		if (s[i] == 'c')
		{
			c = (char)va_arg(arg, int);
			ft_putchar(c);
		}
		else if (s[i] == 's')
		{
			str = va_arg(arg, char*);
			n == 0 ? ft_putstr(str) : ft_putstrn(str, n);
		}
		else if (s[i] == 'p')
		{
			ptr = va_arg(arg, long long int);
			ft_putstr(ft_strjoin("0x",ft_strlowcase(ft_itoa_base(ptr, 16))));
		}
		else if (s[i] == 'd' || s[i] == 'i')
		{
			d = va_arg(arg, long long int);
			n == 0  ? ft_putnbr(d) : ft_putnbrn(d, n, w);
		}
		else if (s[i] == 'o')
		{
			d = va_arg(arg, long long int);
			ft_putstr(ft_itoa_base(d, 8));
		}
		else if (s[i] == 'u')
		{
			d = va_arg(arg, long long int);
			ft_putstr(ft_itoa_base(d, 10));
		}
		else if (s[i] == 'x')
		{
			d = va_arg(arg, long long int);
			ft_putstr(ft_strlowcase(ft_itoa_base(d, 16)));
		}
		else if (s[i] == 'X')
		{
			d = va_arg(arg, long long int);
			ft_putstr(ft_itoa_base(d, 16));
		}
		else if (s[i] == 'f')
		{
			a = va_arg(arg, double);
			ft_putnbrll(a);
			ft_putchar('.');
			n == 0? n = 6 : n;
			ii = n;
			g = 10;
			while (ii-- > 0)
				g = g * 10;
			if (a < 0)
				f = a * (-g);
			else
				f = a * g;
			ft_putnbrf(f, n);
		}
		i++;
//		if (s[i] == '\n')
//		{
//			ft_putchar('\n');
//			i++;
//		}
		while (s[i] != '%' && s[i])
			ft_putchar(s[i++]);
//		break;
	}
	va_end (arg);
}