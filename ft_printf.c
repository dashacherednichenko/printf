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
	int n;
	char *str;
	char *s;
	char c;
	int d;
	unsigned int ptr;
//	char *p;
	va_list arg;
	va_start(arg, fmt);

	i = 0;
	s = fmt;
	n = 0;
	while (s[i])
	{
		while (s[i] != '%')
		{
			ft_putchar(s[i]);
			i++;
		}
		i++;
		if (s[i] == '.')
		{
			i++;
			n = ft_atoi(&s[i]);
			while (s[i] >= '0' && s[i]<= '9')
				i++;
		}
//		printf("n %d\n", n);
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
		else if (s[i] == 'd')
		{
			d = va_arg(arg, unsigned int);
//			printf("n %d\n", n);
			n == 0 ? ft_putnbr(d) : ft_putnbrn(d, n);
		}
		else if (s[i] == 'p')
		{
			ptr = va_arg(arg, unsigned int);
//			p = ft_itoa_base(ptr, 16);
			ft_putstr(ft_strlowcase(ft_itoa_base(ptr, 16)));
		}
/*			int a;
			a = va_arg(arg, int);
			unsigned int p = (unsigned int)&a;
			char s[2*sizeof(p)];
			for(int i = 2*sizeof(p)-1; i >= 0; --i)
			{

				s[i] = "0123456789abcdef"[p & 0x0F];
				p >>= 4;
			}
			for(int i = 0; i < 2*sizeof(p); ++i)
			{
				ft_putchar(s[i]);
			}
		}*/
		i++;
		if (s[i] == '\n')
			ft_putchar('\n');
		break;
		i++;
	}


//	if (!ft_strcmp(format, "%d"))
//	{
//		int x = va_arg(ap, int);
//		printf ("You passed decimal object with value %d\n", x);
//	}
//	if(!ft_strcmp(format, "%s"))
//	{
//		char *p = va_arg (ap, char *);
//		printf ("%s\n", p);
//	}
	va_end (arg);
}