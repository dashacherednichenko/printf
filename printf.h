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
	char			tp;
	char			non_v;
}					t_flags;

int					ft_printf(char *fmt, ...);
int					ft_color_printf(char *fmt, ...);
int					ft_fdprintf(int fd, char *fmt, ...);
int					ft_nb_pass(char *s, int i);
int					ft_print_txt(char *s, t_flags *f, int i, int fd);
int					ft_printnbr(char *s, int fd);
int					ft_precision(char *s, t_flags *f, int i);
int					ft_width(char *s, t_flags *f, int i);
int					ft_pars(va_list ar, t_flags *f, char *s, int fd);
int					ft_pars_tp(va_list ar, t_flags *f, int i, char *s);
int					ft_puts_n(char *str, t_flags *f, int min, int fd);
int					ft_putcharn(char c, t_flags *f, int i, int fd);
int					ft_putnbrll(long long int n, int i);
int					ft_putnbrlln(long long int n, t_flags *f, int fd);
int					ft_putnbrf(va_list ar, t_flags *f, int z, int fd);
unsigned long long int		ft_calcfost(long long int g);
int					ft_calc_nbr(long long int d);
int					ft_ptrtype(long long int d, t_flags *f, int fd);
int					ft_d(va_list ar, t_flags *f, int fd);
int					ft_bin(va_list ar, t_flags *f, int j, int fd);
int					ft_percent(char c, t_flags *f, int fd);
int					ft_octal(long long int d, t_flags *f, int i, int fd);
int					ft_unsig(long long int d, t_flags *f, int i, int fd);
int					ft_hex(long long int d, t_flags *f, int fd);
int					ft_float(va_list ar, t_flags *f, int fd);
char				*ft_strjoinfree(char const *s1, char const *s2, int n);
char				*ft_strtemp(int x, int i, char c);
char				*ft_uitoa_base(unsigned long long int value, int base);
char				*ft_itoa_baseld(long double value, int base);
t_flags				*ft_obnul_fl(t_flags *flags);
t_flags				*ft_nultchn(t_flags *f);

#endif
