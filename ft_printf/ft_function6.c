/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 07:02:56 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/29 07:05:40 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		calci(unsigned long int nb)
{
	int	i;

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(cp = (char*)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

