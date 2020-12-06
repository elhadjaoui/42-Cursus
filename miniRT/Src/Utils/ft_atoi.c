/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 23:28:55 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/04 15:41:32 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double			str_f(char *str)
{
	int		i;
	double	f;
	int		sign;

	i = -1;
	f = 0;
	sign = 1;
	while (str[++i])
	{
		if (str[i] == '-')
			sign = -1;
		if ((str[i] > '/' && str[i] < ':') || str[i] == '.')
		{
			while (str[i] > '/' && str[i] < ':')
				f = f * 10 + str[i++] - 48;
			if (str[i] == '.' && ++i)
			{
				if (str[i] > '/' && str[i] < ':')
					f = (f * 10 + str[i++] - 48) / 10;
			}
			return (f * sign);
		}
	}
	return (f * sign);
}

int				ft_atoi(const char *str)
{
	int				i;
	unsigned	int nb;
	int				sign;

	sign = 1;
	i = -1;
	nb = 0;
	while (str[++i] != '\0')
	{
		if ((str[i] > '/' && str[i] < ':') || str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			if (str[i] == '+' || str[i] == '-')
				i++;
			while (str[i] > '/' && str[i] < ':')
			{
				nb = nb * 10 + str[i++] - 48;
			}
			return (nb * sign);
		}
		else if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (nb * sign);
	}
	return (nb * sign);
}
