/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:58 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:22:00 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

int	get_big_num(t_list *stack)
{
	t_list	*new_stack;
	int		i;

	if (stack)
	{
		new_stack = stack;
		i = new_stack->content;
		while (new_stack)
		{
			if (new_stack->content > i)
				i = new_stack->content;
			new_stack = new_stack->next;
		}
		return (i);
	}
	return (0);
}

void	sa(t_list **stack)
{
	ft_putstr_fd("sa\n", 1);
	swap_stack(stack);
}

int	ft_free(t_list **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (1);
}

int	check_if_sorted(t_list **stack_a)
{
	t_list	*new_stack;

	new_stack = *stack_a;
	while (new_stack)
	{
		if (new_stack->next)
		{
			if (new_stack->content > new_stack->next->content)
				return (0);
		}
		new_stack = new_stack->next;
	}
	return (1);
}

void	check_max_int(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		str++;
	if (ft_strlen(str) > 9)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
