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

static char	*ft_srtfinall(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	tmp = f->zr == 1 ? ft_strtemp(f->w, i, '0') : ft_strtemp(f->w, i, ' ');
	s = f->min == 1 ? ft_strjoinfree(s, tmp, 3) : ft_strjoinfree(tmp, s, 3);
	if (f->type == 'x' || f->type == 'X')
		f->resh == 1 && d != 0 && f->zr == 1 ? s[1] = 'X' : 0;
	return (s);
}

static char	*ft_strprecis(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = ft_strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = ft_strjoinfree(tmp, s, 3) : 0;
	f->resh == 1 && d != 0 && !f->zr ? s = ft_strjoinfree("0X", s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	return (s);
}

int			ft_octal(long long int d, t_flags *f)
{
	char	*s;
	char	*tmp;
	int		i;

	f->mod && !ft_strcmp(f->mod, "h") && f->type != 'O' ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") && f->type != 'O' ? d = (unsigned char)d : 0;
	!f->mod && f->type != 'O' ? d = (unsigned)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	s = ft_uitoa_base(d, 8);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	i = ft_strlen(s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = ft_strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = ft_strjoinfree(tmp, s, 3) : 0;
	f->resh == 1 && !f->zr && f->tchn_t < i && d != 0 ? s = ft_strjoinfree("0", s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w && !f->resh)
		return (0);
	i = ft_strlen(s);
	if (f->w > i)
	{
		tmp = f->zr == 1 ? ft_strtemp(f->w, i, '0') : ft_strtemp(f->w, i, ' ');
		s = f->min == 1 ? ft_strjoinfree(s, tmp, 3) : ft_strjoinfree(tmp, s, 3);
		f->resh == 1 && d != 0 && f->zr == 1 ? s[0] = '0' : 0;
	}
	return (ft_printnbr(s));
}

int			ft_unsig(long long int d, t_flags *f)
{
	char	*s;
	char	*tmp;
	int		i;

	f->type == 'U' ? f->mod = 0 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	(f->mod && !ft_strcmp(f->mod, "ll")) || f->type == 'U' ?\
		d = (unsigned long long)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	!f->mod && f->type != 'U' ? d = (unsigned)d : 0;
	s = ft_uitoa_base(d, 10);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	i = ft_strlen(s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = ft_strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = ft_strjoinfree(tmp, s, 3) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	i = ft_strlen(s);
	if (f->w > i)
		s = ft_srtfinall(s, f, i, d);
	return (ft_printnbr(s));
}

int			ft_hex(long long int d, t_flags *f)
{
	char	*s;
	int		i;

	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	f->mod == 0 ? d = (int)d : 0;
	if (d < 0 && !f->mod)
		s = ft_uitoa_base((unsigned int)d, 16);
	else if ((d < 0 && f->mod && !ft_strcmp(f->mod, "j")) || (f->mod && !ft_strcmp(f->mod, "ll")) || (f->mod && !ft_strcmp(f->mod, "l")))
		s = ft_uitoa_base((unsigned long long int)d, 16);
	else
		s = ft_itoa_base(d, 16);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	s = ft_strprecis(s, f, ft_strlen(s), d);
	i = ft_strlen(s);
	(f->w > i) ? s = ft_srtfinall(s, f, i, d) : 0;
	return (ft_printnbr(f->type == 'X' ? s : ft_strlowcase(s)));
}
