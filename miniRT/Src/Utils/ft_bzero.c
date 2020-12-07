/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:13:28 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/12/07 17:39:35 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void	ft_bzero(void *s, size_t n)
{
	char *h;

	h = (char *)s;
	while (n--)
	{
		*h++ = 0;
	}
}

int		count_commas(char *s)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == ',')
			k++;
		i++;
	}
	return (k);
}

void	print_comma_error(void)
{
	ft_putstr_fd("Error\nMultiple commas between element's informations\n", 2);
	exit(-1);
}

void	print_normal_error(void)
{
	ft_putstr_fd("Error\nWrong VECTOR NORMAL format\n", 2);
	exit(-1);
}
