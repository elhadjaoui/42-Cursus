/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:20:40 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:20:42 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

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
			ft_putstr_fd(" : isn't an integer \n", 2);
			exit(1);
		}
		i++;
	}
}

void	check_duplicate(char *s, t_list *stack)
{
	t_list	*new_stack;

	new_stack = stack;
	while (new_stack)
	{
		if (ft_atoi(s) == new_stack->content)
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd(" : there is a duplicate \n", 2);
			exit(1);
		}
		new_stack = new_stack->next;
	}
}
