/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 11:53:51 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/10 11:53:56 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minitalk.h"

int	get_char(char *bin)
{
	int	i;
	int	element;
	int	base;

	i = 7;
	element = 0;
	base = 1;
	while (i >= 0)
	{
		if (bin[i] == '1')
			element += base;
		base = base * 2;
		i--;
	}
	return (element);
}

void	sig_handler_server(int signum)
{
	static char	*bin;

	if (bin == NULL)
		bin = ft_strdup("");
	if (signum == SIGUSR1)
		bin = ft_strjoin(bin, "0\0");
	if (signum == SIGUSR2)
		bin = ft_strjoin(bin, "1\0");
	if (ft_strlen(bin) == 8)
	{
		print_char(get_char(bin));
		free(bin);
		bin = NULL;
	}
}

int	main(void)
{
	pid_t	pid;
	char	*id;

	signal(SIGUSR1, sig_handler_server);
	signal(SIGUSR2, sig_handler_server);
	pid = getpid();
	id = ft_itoa(pid);
	ft_putstr_fd("PID = ", 1);
	ft_putstr_fd(id, 1);
	ft_putstr_fd("\n", 1);
	free(id);
	while (1)
		pause();
	return (0);
}
