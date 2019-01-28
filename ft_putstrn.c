/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:55:12 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/03 12:55:15 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putstrn(char *str, int n)
{
	int i;

	i = 0;
	if (n == 0)
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
	else
	{
		while (str[i] && i < n)
			ft_putchar(str[i++]);
	}
	return (i);
}