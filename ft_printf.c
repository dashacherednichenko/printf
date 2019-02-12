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

#include "printf.h"

int	ft_printf(char *fmt, ...)
{
	int					i;
	char				*s;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	i = 0;
	s = fmt;
	f->l = 0;
	f->l = ft_pars(ar, f, i, s);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}

 int ft_color_printf(char *fmt, ...)
 {
//	char *C_off;
//	char *C_blac;
//	char *C_redd;
//	char *C_gree;
//	char *C_yell;
//	char *C_blue;
//	char *C_purp;
//	char *C_cyan;
//	char *C_whit;
	int					i;
	int ii;
	char				*s;
	char 				*s2;
//	char 				*ns[1000];
	t_flags				*f;
	va_list				ar;

//	{C_off} = "\033[0m";
//	{C_blac} = "\033[30m";
//	{C_redd} = "\033[31m";
//	{C_gree} = "\033[32m";
//	{C_yell} = "\033[33m";
//	{C_blue} = "\033[34m";
//	{C_purp} = "\033[35m";
//	{C_cyan} = "\033[36m";
//	{C_whit} = "\033[37m";
	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	i = 0;
	s = fmt;
	while (s[i])
	{
		if(!ft_strncmp(&s[i], "{C_off}", 7))
		{
			ii = 0;
			s2 = "{C_off}";
			while (s2[ii] != '\0' && ii < 7 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_blac}", 8))
		{
			ii = 0;
			s2 = "{C_blac}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}

		}
		if(!ft_strncmp(&s[i], "{C_redd}", 8))
		{
			ii = 0;
			s2 = "{C_redd}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}

		}
		if(!ft_strncmp(&s[i], "{C_gree}", 8))
		{
			ii = 0;
			s2 = "{C_gree}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_yell}", 8))
		{
			ii = 0;
			s2 = "{C_yell}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_blue}", 8))
		{
			ii = 0;
			s2 = "\033[34m";
			s = ft_strncpy(&s[i], "\033[34m", 8);
//			&s[i] = &s2[ii];
//			i = i + 8;
			while (ii < 8)
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_purp}", 8))
		{
			ii = 0;
			s2 = "{C_purp}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_cyan}", 8))
		{
			ii = 0;
			s2 = "{C_cyan}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		if(!ft_strncmp(&s[i], "{C_whit}", 8))
		{
			ii = 0;
			s2 = "{C_whit}";
			while (s2[ii] != '\0' && ii < 8 && s[i])
			{
				s[i++] = s2[ii++];
			}
		}
		i++;
	}
	f->l = 0;
	i = 0;
	f->l = ft_pars(ar, f, i, s);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
 }
