/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:33:03 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/09 22:27:40 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int k;

	if (n < 0)
	{
		ft_putchar('-', fd);
		n = n * -1;
	}
	k = n;
	if (k < 10)
	{
		ft_putchar(k + '0', fd);
	}
	else
	{
		ft_putnbr_fd(k / 10, fd);
		ft_putnbr_fd(k % 10, fd);
	}
}
