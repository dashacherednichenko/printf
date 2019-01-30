/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiven <dpiven@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:43:38 by dpiven            #+#    #+#             */
/*   Updated: 2019/01/30 17:43:39 by dpiven           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int n)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (n == 1)
		free(s1);
	if (n == 2)
		free(s2);
	if (n == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
