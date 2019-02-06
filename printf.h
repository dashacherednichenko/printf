/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:38:15 by dpiven            #+#    #+#             */
/*   Updated: 2018/12/27 15:38:21 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

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
	int				percent;
	long long int	w;
	long long int	tchn;
	int				tchn_t;
	char			*mod;
	char			type;
}					t_flags;

int					ft_printf(char *fmt, ...);
int					ft_nb_pass(char *s, int i);
int					ft_print_txt(char *s, t_flags *f, int i);
int					ft_printnbr(char *s);
int					ft_precision(char *s, t_flags *f, int i);
int					ft_width(char *s, t_flags *f, int i);
int					ft_pars(va_list ar, t_flags *f, int i, char *s);
int					ft_pars_type(va_list ar, t_flags *f, int i, char *s);
int					ft_putstrn(char *str, t_flags *flags);
int					ft_putcharn(char c, t_flags *flags);
void				ft_putnbrll(long long int n);
int					ft_putnbrlln(long long int n, t_flags *f);
void				ft_putnbrf(unsigned long long int n, long long int z);
long long int		ft_calcnbrost(long long int g);
int					ft_calc_nbr(long long int d);
int					ft_ptrtype(long long int d, t_flags *flags);
int					ft_d(va_list ar, t_flags *flags);
int					ft_percent(char c, t_flags *flags);
int					ft_octal(long long int d, t_flags *flags);
int					ft_unsig(long long int d, t_flags *f);
int					ft_hex(long long int d, t_flags *f);
int					ft_float(va_list ar, t_flags *f);
char				*ft_strjoinfree(char const *s1, char const *s2, int n);
char				*ft_strtemp(int x, int i, char c);
char				*ft_uitoa_base(unsigned long long int value, int base);
t_flags				*ft_obnul_fl(t_flags *flags);

#endif
