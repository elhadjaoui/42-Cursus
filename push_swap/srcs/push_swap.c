/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:20:59 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:00 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	push_to_stack_b(t_list **stack_a, t_list **stack_b, t_list *chunk)
{
	int	position;
	int	content;

	content = get_content(*stack_a, chunk);
	position = GetNth(*stack_a, content);
	if (position <= (ft_lstsize(*stack_a)) / 2)
		get_content2top_of_stack(stack_a, content, "ra\n");
	else
		get_content2top_of_stack_reverse(stack_a, content, "rra\n");
	ft_putstr_fd("pb\n", 1);
	push_b(stack_a, stack_b);
}

void	free_chunk(t_list **chunk)
{
	while (*chunk)
		pop(chunk);
}

void	get_chunk(int *numbers, t_list **chunk, int size)
{
	int	i;

	i = 0;
	while (i < 40 && i < size)
	{
		ft_lstadd_back(chunk, ft_lstnew(*numbers));
		i++;
		numbers++;
	}
}

void	sorte_stack(t_list **stack_a, t_list **stack_b)
{
	int		*numbers;
	int		*witness;
	t_list	*chunk;
	t_list	*stack;

	if (ft_lstsize(*stack_a) > 4)
	{
		numbers = malloc(sizeof(int) * ft_lstsize(*stack_a));
		chunk = NULL;
		witness = numbers;
		get_sorted_list(numbers, *stack_a);
		stack = *stack_a;
		get_chunk(numbers, &chunk, ft_lstsize(*stack_a) - 3);
		while (equal_number_in_chunk(*stack_a, chunk))
			push_to_stack_b(stack_a, stack_b, chunk);
		free(witness);
		free_chunk(&chunk);
		if (!check_if_sorted(stack_a))
			sorte_stack(stack_a, stack_b);
	}
	else
		sorte_3_number(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = create_stack(argc, argv);
	stack_b = NULL;
	if (ft_lstsize(stack_a) != 1)
	{
		if (ft_lstsize(stack_a) != 2)
		{
			if (!check_if_sorted(&stack_a))
			{
				sorte_stack(&stack_a, &stack_b);
				send_back2stack_a(&stack_a, &stack_b);
			}
		}
		if (!check_if_sorted(&stack_a))
			sa(&stack_a);
	}
}
