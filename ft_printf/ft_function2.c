/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:55:48 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 06:56:04 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
char *ft_hextos(unsigned int n, char c)
{
	char *s;
	s = NULL;
	if (c == 'u')
		return ft_uinttos(n);
	if (n == 0)
		return ft_strdup("0");
	while (n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15)
			s = ft_strjoin(ft_ctos(n % 16 + 55), s);
		else
			s = ft_strjoin(ft_itoa(n % 16), s);
		n = n / 16;
	}

	return (c == 'x' ? ft_strdup(ft_tolower(s)) : (s));
}

char * ft_sp_ze(int a, int b, char *s, char o)
{
	int k;
	int j;
	int len;

	k = 0;
	j = 0;
	if ((a < 0) && (j = 1))
		a *= -1;
	len = ft_strlen(s);
	if (o == '%' && b != -1 && b >= a)
	 	b = 0;
	if (s[0] == '-')
		len--;
	if (ft_ft_atoi(s) == 0)
		len = 0;
	if (a >= b && a >= len  && j != 1) 
		return func1(a, b,s);
	if (a >= b && a >= len  && j == 1)
		return   func2(a, b, s);
	else if (b >= a && b > len )
		return func3(b, s);
	return (s);
}

char *ft_sp_string(int a, int b, char *s, int o)
{

	char *p;
	int k;
	int j;
	int len;

	k = 0;
	p = ft_strdup("");
	p = ft_strdup("");
	len = ft_strlen(s);
	if (b >= len || b < 0)
		b = len;
	j = 0;

	if ( a < 0 && (o = 2))
		a *= -1;
	while (  (a - b != 0)  && a--)
		p = ft_strjoin(p,ft_strdup(" "));
	if (b > a && b > len)
		return s;
	if (b > a)
	{
		s[b] = '\0';
		return s;
	}
	s[b] = '\0';
	return  o == 2 ? ft_strjoin(s, p) : ft_strjoin(p, s);
}

char *ft_cv(char p, va_list ap , int k)
{
	char *tt;
	char c;

	if (p == 'd' || p == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (p == 'x' || p == 'X' || p == 'u')
		return (ft_hextos(va_arg(ap, unsigned int), p));
	else if (p == 's')
	{
		tt = va_arg(ap, char *);
		return ((tt != NULL) ? ft_strdup(tt):
				ft_strdup("(null)"));
	}
	else if (p == 'c')
	{
		c = va_arg(ap, int);
		if (c == '\0' || c == '\t')
			return ft_ctos(c);
		else
			return  ft_ctos(c);
	}
	else if (p == '%')
		return(ft_ctos('%'));
	else if (p == 'p')
		return (ft_phextos(va_arg(ap, unsigned long int),k));
	return (ft_ctos(p));
}

