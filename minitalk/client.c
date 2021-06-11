/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:52:20 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/10 11:52:25 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minitalk.h"

void	get_binaryof_char(int character, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (character & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

void	send_newline(int pid)
{
	char	*newline;

	newline = "\n\n";
	while (*newline)
	{
		get_binaryof_char(*newline, pid);
		newline++;
	}
}

int	main(int argc, char **argv)
{
	char	*error;
	char	*str;
	int		pid;

	if (argc == 3)
	{
		check_if_integer(argv[1]);
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			get_binaryof_char(*str, pid);
			str++;
		}
		send_newline(pid);
	}
	else
	{
		error = "Error\nfew/many arguments";
		write(1, error, ft_strlen(error));
	}
	return (0);
}
