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

#include "../header/minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
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

void	check_if_integer(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] > '/' && s[i] < ':') && s[i] != '+' && s[i] != '-')
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd(" : in PID isn't an integer \n", 2);
			exit(1);
		}
		i++;
	}
}
