/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 00:44:18 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/13 20:14:40 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int lens;

	lens = ft_strlen(src);
	i = 0;
	if (dst)
	{
		while (*dst && size)
		{
			size--;
			i++;
			dst++;
		}
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	if (size != 0)
	{
		*dst = 0;
	}
	return (i + lens);
}
