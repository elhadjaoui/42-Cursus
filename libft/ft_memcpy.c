/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:16:22 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 15:10:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *k;
	char *h;

	k = (char*)dst;
	h = (char*)src;
	if (h == k || n == 0)
		return (k);
	while (n--)
	{
		*k++ = *h++;
	}
	return (dst);
}
