/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:41 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:43 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	get_content2top_of_stack_reverse(t_list **stack, int content, char *op)
{
	int	pos;

	pos = GetNth(*stack, content);
	while (GetNth(*stack, content))
	{
		ft_putstr_fd(op, 1);
		reverse_rotate_stack(stack);
	}
}

void	fill_numbers(int *numbers, t_list *stack)
{
	int		i;
	t_list	*new_stack;

	if (stack)
	{
		new_stack = stack;
		i = 0;
		while (new_stack)
		{
			numbers[i] = new_stack->content;
			i++;
			new_stack = new_stack->next;
		}
	}
}

int	equal_number_in_chunk(t_list *stack_a, t_list *chunk)
{
	t_list	*stack;
	t_list	*chunk_stack;

	stack = stack_a;
	while (stack)
	{
		chunk_stack = chunk;
		while (chunk_stack)
		{
			if (stack->content == chunk_stack->content)
				return (1);
			chunk_stack = chunk_stack->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	get_content(t_list *stack_a, t_list *chunk)
{
	t_list	*stack;
	t_list	*chunk_stack;

	stack = stack_a;
	while (stack)
	{
		chunk_stack = chunk;
		while (chunk_stack)
		{
			if (stack->content == chunk_stack->content)
				return (stack->content);
			chunk_stack = chunk_stack->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	send_back2stack_a(t_list **stack_a, t_list **stack_b)
{
	int	big_num;
	int	position;

	while (ft_lstsize(*stack_b) != 0)
	{
		big_num = get_big_num(*stack_b);
		position = GetNth(*stack_b, big_num);
		if (position <= (ft_lstsize(*stack_b)) / 2)
			get_content2top_of_stack(stack_b, big_num, "rb\n");
		else
			get_content2top_of_stack_reverse(stack_b, big_num, "rrb\n");
		ft_putstr_fd("pa\n", 1);
		push_a(stack_b, stack_a);
	}
}
