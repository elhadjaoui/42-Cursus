/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:20:50 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:20:52 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	swap_stack(t_list **stack)
{
	int	a;

	if (ft_lstsize(*stack) > 1)
	{
		a = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = a;
	}
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	if (*stack_b)
	{
		push_front(stack_a, (*stack_b)->content);
		pop(stack_b);
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a)
	{
		push_front(stack_b, (*stack_a)->content);
		pop(stack_a);
	}
}

void	rotate_stack(t_list **stack)
{
	if (*stack && ft_lstsize(*stack) > 1)
	{
		push_back(stack, (*stack)->content);
		pop(stack);
	}
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*new_stack;

	if (ft_lstsize(*stack) > 1)
	{
		new_stack = *stack;
		while (new_stack)
		{
			if (new_stack->next->next == NULL)
			{
				push_front(stack, new_stack->next->content);
				ft_free(&(new_stack)->next);
				break ;
			}
			new_stack = new_stack->next;
		}
	}
}
