/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:40:09 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:20:04 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"
#include "../headers/get_next_line.h"

void	check_stack_is_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_stack;

	new_stack = *stack_a;
	if (ft_lstsize(*stack_b) == 0)
	{
		while (new_stack)
		{
			if (new_stack->next)
			{
				if (new_stack->content > new_stack->next->content)
				{
					ft_putstr_fd("KO\n", 1);
					return ;
				}
			}
			new_stack = new_stack->next;
		}
		ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 1);
}

void	which_operation(char *str, t_list **stack_a, t_list **stack_b)
{
	if (cmp(str, "rr"))
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
	else if (cmp(str, "rra"))
		reverse_rotate_stack(stack_a);
	else if (cmp(str, "rrb"))
		reverse_rotate_stack(stack_b);
	else if (cmp(str, "rrr"))
	{
		reverse_rotate_stack(stack_a);
		reverse_rotate_stack(stack_b);
	}
	else if (cmp(str, "rb"))
		rotate_stack(stack_b);
	else
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("You have entered instructions that don't exist \n", 1);
		exit(1);
	}
}

void	check_which_operation(char **op, t_list **stack_a, t_list **stack_b)
{
	while (get_next_line(0, op))
	{
		if (cmp(*op, "sa"))
			swap_stack(stack_a);
		else if (cmp(*op, "sb"))
			swap_stack(stack_b);
		else if (cmp(*op, "ss"))
		{
			swap_stack(stack_a);
			swap_stack(stack_b);
		}
		else if (cmp(*op, "pa"))
			push_a(stack_b, stack_a);
		else if (cmp(*op, "pb"))
			push_b(stack_a, stack_b);
		else if (cmp(*op, "ra"))
			rotate_stack(stack_a);
		else
			which_operation(*op, stack_a, stack_b);
		free(*op);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*op;

	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	check_which_operation(&op, &stack_a, &stack_b);
	check_stack_is_sorted(&stack_a, &stack_b);
	free(op);
}
