/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:38:15 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:38:21 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				l;
	int				min;
	int				plus;
	int				space;
	int				resh;
	int				zr;
	long long int	w;
	long long int	tchn;
	int				tchn_t;
	char			*mod;
	char			type;
}					t_flags;

typedef struct		s_lst
{
	t_flags			flags;
	struct s_lst	*next;
}					t_lst;

int					ft_printf(char *fmt, ...);
int					ft_nb_pass(char *s, int i);
int					ft_print_txt(char *s, t_flags *f, int i);
int					ft_precision(char *s, t_flags *f, int i);
int					ft_width(char *s, t_flags *f, int i);
int					ft_pars(va_list ar, t_flags *f, int i, char *s);
int					ft_pars_type(va_list ar, t_flags *f, int i, char *s);
int					ft_putstrn(char *str, t_flags *flags);
int					ft_putcharn(char c, t_flags *flags);
void				ft_putnbrn(int n, int z, int w);
void				ft_putnbrll(long long int n);
void				ft_putnbrlln(long long int n, int z);
void				ft_putnbrf(unsigned long long int n, long long int z);
long long int		ft_calcnbrost(long long int g);
int					ft_ptrtype(long long int d, t_flags *flags);
int					ft_d(va_list ar, t_flags *flags);
int					ft_octal(long long int d, t_flags *flags);
int					ft_unsig(long long int d, t_flags *f);
int					ft_hex_low(long long int d, t_flags *f);
int					ft_hex(long long int d, t_flags *f);
int					ft_float(va_list ar, t_flags *f);
char				*ft_strjoinfree(char const *s1, char const *s2, int n);
char				*ft_strtemp(int x, int i, char c);
t_flags				*ft_obnul_fl(t_flags *flags);

#endif
