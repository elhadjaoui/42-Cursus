/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:00:43 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 21:17:03 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		p[i] = (f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
