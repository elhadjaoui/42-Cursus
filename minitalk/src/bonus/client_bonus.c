/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:36 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/10 11:53:39 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minitalk.h"

int	get_binaryof_char(int character, int pid)
{
	int	i;
	int	check;

	i = 7;
	while (i >= 0)
	{
		if (character & (1 << i))
			check = kill(pid, SIGUSR2);
		else
			check = kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
	return (check);
}

void	check_check(int check)
{
	if (check == 0)
		ft_putstr_fd("signal has been sent successfully\n", 1);
	else
		ft_putstr_fd("something went wrong while sending the message\n", 1);
}

void	send_prefix(int pid)
{
	char	*prefix;
	int		check;

	prefix = "Message : ";
	while (*prefix)
	{
		check = get_binaryof_char(*prefix, pid);
		prefix++;
	}
}

void	send_newline(int pid)
{
	char	*newline;
	int		check;

	newline = "\n\n";
	while (*newline)
	{
		check = get_binaryof_char(*newline, pid);
		newline++;
	}
	check_check(check);
}

int	main(int argc, char **argv)
{
	char	*error;
	char	*str;
	int		check;
	int		pid;

	if (argc == 3)
	{
		check_if_integer(argv[1]);
		str = argv[2];
		pid = ft_atoi(argv[1]);
		send_prefix(pid);
		while (*str)
		{
			check = get_binaryof_char(*str, pid);
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
