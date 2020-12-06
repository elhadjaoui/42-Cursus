/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:48:56 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 06:51:28 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_isflag(char p)
{
	if (p == '.' || p == '*' || p == '-' || (p >= 48 && p <= 57))
		return (1);
	if (p != 's' || p != 'd' || p != 'u' || p != 'i' || p != 'x' ||
			p != 'X' || p != 'p' || p != 'c' || p != '%')
		return (2);
	return (0);
}

int ft_flag(const char **l, va_list ap, int dot, int z)
{
	int nu1;
	int nu2;
	int s;

	nu2 = 0;
	if (ft_isflag(**l) == 1 && (nu1 = 0) == 0)
	{
		while (ft_isflag(**l) != 2)
			if (**l == '.' && (*l)++)
				dot = 1;
			else if (**l == '0' && (*l)++)
				z = 1;
			else if ((**l >= 48 && **l <= 57) || **l == '-' || **l == '*')
			 (!dot) ? (nu1 = ft_atoi(l, ap)) :(nu2 = ft_atoi(l, ap));
		if ((z == 1 && nu2 < 0 &&  nu1 > 0 && **l != 's') || (**l == '%' && dot == 1 && z == 1))
			s = ft_putstr(fucking_star(nu1, ft_cv(**l, ap,1)));
		else if ((dot == 0 && nu2 == 0 && (nu2 = -1) && z == 1 && **l != 's'))
			s = ft_putstr(unique(nu1,ft_cv(**l, ap,1)));
		else
			s = hadihia(**l, nu1, nu2, ap);
	}
	else
		s = ft_putstr(ft_cv(**l, ap,1));
	return (s);
}
