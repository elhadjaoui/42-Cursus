/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:35:09 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 16:02:28 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calci(unsigned int nb)
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

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned	int	copy;
	int				i;
	int				sign;

	sign = 0;
	if (n < 0 && ++sign)
		copy = n * -1;
	else
		copy = n;
	i = calci(copy);
	if (!(ptr = malloc(i + sign + 1)))
		return (NULL);
	ptr[i + sign] = '\0';
	while (copy > 9)
	{
		ptr[--i + sign] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i + sign] = copy + 48;
	if (n < 0)
		ptr[--i + sign] = '-';
	return (ptr);
}
