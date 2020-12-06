/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:54:46 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 20:45:44 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*f;
	char	*t;
	size_t	a;

	f = (char*)src;
	t = (char*)dst;
	a = len;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len--)
			t[len] = f[len];
	else
		while (len--)
			*t++ = *f++;
	return (dst);
}
