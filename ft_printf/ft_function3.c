/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:56:37 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 06:58:59 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *func2(int a,int b,char *s)
{
	int temoin;
	int k;
	char *ptr;
	char *ko;
	int len;

	k = 0;
	ko = s;
	ptr = ft_strdup("");
	len = ft_strlen(s);
	temoin = b;
	if (ft_ft_atoi(s) == 2)
		len++;
	if (s[0] == '-' && a--)
		len--;
	if (ft_ft_atoi(s) == 0 && b == 0)
	{
		len = 0;
		s = ft_strdup("");
	}
	if (s[0] == '-')
	{
		s = s + 1;
		ptr = ft_strdup("-");
	}
	if (b > len && (k += len))
		while (b - len != 0 && b >= 0 && b--)
			s = ft_strjoin(ft_strdup("0"), s);
	b = temoin;
	while ((a - b != 0) && (a - len > 0) && a--)
		s = ft_strjoin(s ,ft_strdup(" "));
	s = ft_strjoin(ptr,s);
	return (s);
}

char *func3(int b,char *s)
{
	int k;
	char *ptr;
	char *ko;
	char *p;

	p = ft_strdup("");
	k = ft_strlen(s);
	ko = s;

	ptr = ft_strdup("");
	if (s[0] == '-' && --k)
	{
		s = s + 1;
		ptr = ft_strdup("-");

	}
	while(b - k != 0 && b != 0 && --b)
		p = ft_strjoin(p,ft_strdup("0"));
	p = ft_strjoin(ptr,p);

	return ft_strjoin(p,s);
}

char *ft_tolower(char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'F')
			c[i] = c[i] + 32;
		i++;
	}
	return (c);
}


char *ft_phextos(unsigned long int n ,int i)
{
	char *s;
	char *ptr;

	s = NULL;
	ptr = ft_strdup("0x0");
	while(n > 0)
	{
		if (n % 16 >= 10 && n % 16 <= 15 )
			s = ft_strjoin(ft_ctos(n % 16 + 55), s);
		else
			s = ft_strjoin(ft_itoa(n % 16),s);
		n = n / 16;
	}
	if (i == 0)
		ptr = ft_strdup("0x");
	return (s == NULL ? ptr : ft_strjoin(ft_strdup("0x"),ft_strdup(ft_tolower(s))));
}

int ft_atoi(const char **str, va_list ap)
{
	int nb;
	int sign;
	int k;

	nb = 0;
	sign = 1;
	if (**str == '-' && (*str)++)
		sign = -1;
	if (**str == '*' && (*str)++)
	{
		nb = va_arg(ap, int);
		k = nb;
	}
	else
		while (**str > '/' && **str < ':')
		{
			nb = nb * 10 + **str - 48;
			(*str)++;
		}
	if (sign == -1 && k < 0)
		sign = 1;
	return (nb * sign);
}
