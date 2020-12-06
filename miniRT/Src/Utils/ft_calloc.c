/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 00:45:04 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 21:05:07 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *p;

	p = malloc(count * size);
	if (p != NULL)
	{
		ft_bzero(p, count * size);
		return (p);
	}
	return (NULL);
}
