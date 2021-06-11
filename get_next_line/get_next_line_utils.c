/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:57:28 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/03/02 13:15:10 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*p;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = len(s1);
	len2 = len(s2);
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

char	*sone(char *s)
{
	char	*p;
	int		k;

	k = 0;
	while (s && s[k] != '\n' && *s)
		k++;
	if (!(p = (char*)malloc(k + 1)))
		return (NULL);
	while (s && *s && *s != '\n')
		*p++ = *s++;
	*p = '\0';
	p = p - k;
	return (p);
}

char	*stwo(char *s)
{
	char	*p;
	size_t	k;
	size_t	l;
	size_t	y;

	k = 0;
	l = 0;
	while (s && s[k] && s[k] != '\n')
		k++;
	if (s && s[k] == '\0')
		y = 0;
	else
	{
		y = ++k;
		while (s && s[k])
			k++;
	}
	if (!(p = (char*)malloc((k - y) + 1)))
		return (NULL);
	while (y < k)
		p[l++] = s[y++];
	p[l] = '\0';
	return (p);
}

size_t	len(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*dpl(char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	while (s1 != NULL && s1[i] != '\0')
		i++;
	if (!(cp = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
