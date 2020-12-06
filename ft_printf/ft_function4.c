/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 06:59:08 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 07:00:32 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_uinttos(unsigned int n)
{   
	char			*ptr;
	unsigned	int	copy;
	int				i;

	copy = n;
	i = calci(copy);
	if (!(ptr = malloc(i  + 1)))
		return (NULL);
	ptr[i] = '\0';
	while (copy > 9)
	{
		ptr[--i] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i] = copy + 48;
	return (ptr);

}

void	ft_bzero(void *s, size_t n)
{
	char *h;

	h = (char *)s;
	while (n--)
		*h++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void *p;

	p = malloc(count * size);
	if (p != NULL)
	{
		ft_bzero(p, count * size);
		return (p);
	}
	return (NULL);
}

int ft_ft_atoi(const char *str)
{

	int nb;
	int sign;
	int o;
	int test;

	o = 0;
	test = 0;
	nb = 0;
	sign = 1;
	if ( str[o] == '\0')
		test = 2;
	while (str[o] != '\0')
	{
		if ((str[o] >= 'a' && str[o] <= 'z') || (str[o] >= 'A' && str[o] <= 'Z' )
				|| str[o] == '\t'|| str[o] == 'x' || str[o] == '%')
			test = 1;

		o++;
	}
	if (*str == '-' && (str)++)
		sign = -1;
	while (*str > '/' && *str < ':')
	{
		nb = nb * 10 + *str - 48;
		(str)++;
	}
	return test == 1 || test == 2 ? (test) : (nb * sign);
}

char *func1(int a,int b,char *s)
{


	int k;
	char *ptr;
	char *p;
	int len;
	k = 0;
	p = ft_strdup("");
	ptr = ft_strdup("");
	len = ft_strlen(s);
	if (s[0] == '-' && a--)
		len--;
	if (s[0] == '-')
	{
		s =  s + 1;
		p = ft_strjoin(p,ft_strdup("-"));
	} 
	if (ft_ft_atoi(s) == 2)
		len++;

	if (ft_ft_atoi(s) == 0  && b != -1)
	{
		len  = 0;
		s = ft_strdup("");
	}
	while((a - b > 0) && (a - len > 0) && a--)
		p = ft_strjoin(ft_strdup(" "),p);

	if (b > len){
		while(b - len != 0 && b != 0 && b--)
			p = ft_strjoin(p,ft_strdup("0"));
	}

	return  ft_strjoin(p,s);
}
