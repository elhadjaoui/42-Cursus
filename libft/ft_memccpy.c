/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:41:37 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/04 15:32:40 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char*)src)[i] == (unsigned char)c)
		{
			((unsigned char*)dst)[i++] = (unsigned char)c;
			return (&dst[i]);
		}
		((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (NULL);
}
