/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:36:09 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 16:11:17 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			o;
	unsigned	int	k;

	o = len;
	k = 0;
	if (!(p = (char*)malloc(len + 1)))
		return (NULL);
	if (ft_strlen(s) < start || s == NULL)
		return (ft_strdup(""));
	k = (unsigned int)ft_strlen(s);
	while (s && len > 0)
	{
		*p++ = s[start];
		start++;
		len--;
	}
	*p = '\0';
	p = p - o;
	return (p);
}
