/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:46:34 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 06:48:21 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"


int check_c(va_list ap, const char **s)
{
	va_list ok;
	int i;
	int out;

	va_copy(ok, ap);
	i = 0;
	out = 0;
	while (ft_isflag(s[0][i]) == 1)
	{
		if (s[0][i] == '-')
			out = -1;
		if (s[0][i] == '*' && (out = va_arg(ok, int)) < 0)
			out = -1;
		i++;
	}
	if (s[0][i] == 'c' && va_arg(ok, int) == 0)
	{
		if (out < 0)
		{
			out += write(1, "\0", 1) + 1;
			out += ft_flag(s, ap, 0, 0);
		}
		else
		{
			out = ft_flag(s, ap, 0, 0);
			out += write(1, "\0", 1);
		}
	}
	return (out);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int s;
	int a;

	va_start(ap, fmt);
	s = 0;
	a = 0;
	while (*fmt != 0)
	{
		if (*fmt == '%' && ++fmt)
		{
			a = check_c(ap, &fmt);
			if ((a  <= 0 && (!(a = 0))))
				s += ft_flag(&fmt, ap, 0, 0);
			s += a;
		}
		else
			s +=  write(1,fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (s);
}



