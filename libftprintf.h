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
	int				min;
	int				plus;
	int				space;
	int 			resh;
	int				zero;
	int 			width;
	int				precision;
	char 			*mod;
	char 			type;
}					t_flags;

typedef struct		s_lst
{
	t_flags			flags;
	struct s_lst	*next;
}					t_lst;

void ft_printf(char *fmt, ...);
void ft_putstrn(char *str, int n);
void ft_putnbrn(int n, int z, int w);
void ft_putnbrll(long long int n);
void ft_putnbrlln(long long int n, int z);
void ft_putnbrf(unsigned long long int n, long long int z);

#endif
