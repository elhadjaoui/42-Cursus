/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:52:54 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 06:55:22 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *unique(int nu1,char *ptr)
{
	int len;
	char *ptt;
	char *ko;

	ko = ptr;
	len = ft_strlen(ptr);
	ptt = ft_strdup("");
	if (ptr[0] == '-')
	{
		ptr = ptr + 1;
		ptt = ft_strdup("-");
	}
	if (nu1 < 0 && 	(nu1*=-1))
		while (nu1 - len != 0 && nu1 > len )
		{
			ptr = ft_strjoin(ptr,ft_strdup(" "));
			nu1--;
		}
		
	else
		while (nu1 - len != 0 && nu1 > len)
		{
			ptr = ft_strjoin(ft_strdup("0"), ptr);
			nu1--;
		}
	ptr = ft_strjoin(ptt, ptr);

	free(ko);
	return ptr;
}

char *fucking_star(int nu1, char *ptr)
{
	int len;
	char *ptt;
	char *ko;
	char *s;

	ko = ptr;
	len = ft_strlen(ptr);
	ptt = ft_strdup("");
	s = ft_strdup("");
	if (ptr[0] == '-')
	{
		ptr = ptr + 1;
		ptt = ft_strdup("-");
	}
	while (nu1 - len > 0)
	{
		ptr = ft_strjoin(ft_strdup("0"), ptr);
		nu1--;
	}
	ptr = ft_strjoin(ptt, ptr);
	return ptr;
}

int hadihia(char p, int nu1, int nu2, va_list ap)
{
	if (p == 'd' || p == 'i' || p == 'x' || p == 'X' || p == 'u'
			|| p == 'p' || p == 'c' || p == '%')
		return ft_putstr(ft_sp_ze(nu1, nu2, ft_cv(p, ap,nu2),p));

	if (p == 's')
		return ft_putstr(ft_sp_string(nu1, nu2, ft_cv(p, ap,1), 1));
	return (0);
		
}

