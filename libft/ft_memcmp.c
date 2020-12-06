/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:26:06 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/07 12:14:34 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char *to;
	unsigned	char *from;

	to = (unsigned char*)s1;
	from = (unsigned char*)s2;
	while (n--)
	{
		if (*to != *from)
			return (*to - *from);
		to++;
		from++;
	}
	return (0);
}
