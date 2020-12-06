/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:00:59 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 07:02:37 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char    *ft_strjoin(char  *s1, char  *s2)
{
	int        len1;
	int        len2;

	char    *p;

	if (s1 == NULL)
		s1 = ft_strdup("");
	if  (s2 == NULL)
		s2 = ft_strdup("");
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	p = (char*)malloc(len2 + len1 + 1);
	if (p == NULL)
		return (NULL);
	while (len1 != 0 && *s1 != '\0')
		*p++ = *s1++;
	while (*s2 != '\0')
		*p++ = *s2++;
	*p = '\0';
	p = p - (len2 + len1);

	return (p);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned	int	copy;
	int				i;
	int				sign;

	sign = 0;
	if (n < 0 && ++sign)
		copy = n * -1;
	else
		copy = n;
	i = calci(copy);
	if (!(ptr = malloc(i + sign + 1)))
		return (NULL);
	ptr[i + sign] = '\0';
	while (copy > 9)
	{
		ptr[--i + sign] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i + sign] = copy + 48;
	if (n < 0)
		ptr[--i + sign] = '-';
	return (ptr);
}
char *ft_ctos(char c)
{

	char *p;
	p = malloc(2 * sizeof(char));
	p[0] = c;
	p[1] = 0;
	return p;
}


size_t	ft_putstr(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	free(str);
	return(i);
}
