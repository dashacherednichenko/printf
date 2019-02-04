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

int	ft_octal(long long int d, t_flags *f)
{
	char	*str;
	int		i;

	ft_putstr(str = ft_itoa_base(d, 8));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}

int	ft_unsig(long long int d, t_flags *f)
{
	char	*str;
	int		i;

	ft_putstr(str = ft_itoa_base(d, 10));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}

int	ft_hex_low(long long int d, t_flags *f)
{
	char	*str;
	int		i;

	ft_putstr(str = ft_strlowcase(ft_itoa_base(d, 16)));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}

int	ft_hex(long long int d, t_flags *f)
{
	char 	*str;
	int		i;

	ft_putstr(str = ft_itoa_base(d, 16));
	i = ft_strlen(str);
	f->min = 0;
	free(str);
	return (i);
}
