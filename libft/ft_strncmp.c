/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:58:46 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 20:29:58 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if ((!*s1 || !*s2) && n)
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	while (n--)
	{
		if (*(unsigned char*)s1 != *(unsigned char*)s2 || !*s1 || !*s2)
			return (*(unsigned char*)s1 - *(unsigned char*)s2);
		s1++;
		s2++;
	}
	return (0);
}
