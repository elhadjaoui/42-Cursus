/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:48 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:50 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	ra(t_list **stack)
{
	ft_putstr_fd("ra\n", 1);
	rotate_stack(stack);
}

void	rra(t_list **stack)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate_stack(stack);
}

void	sorte_3_number(t_list **stack_a)
{
	int	*numbers;

	numbers = malloc(sizeof(int) * 3);
	fill_numbers(numbers, *stack_a);
	if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] < numbers[2])
		sa(stack_a);
	else if (numbers[0] > numbers[1] && numbers[1] > numbers[2])
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] > numbers[2])
		ra(stack_a);
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[0] < numbers[2])
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2])
		rra(stack_a);
	free(numbers);
}

void	get_sorted_list(int *numbers, t_list *stack)
{
	fill_numbers(numbers, stack);
	quicksort(numbers, 0, ft_lstsize(stack) - 1);
}

void	get_content2top_of_stack(t_list **stack, int content, char *op)
{
	while (GetNth(*stack, content))
	{
		ft_putstr_fd(op, 1);
		rotate_stack(stack);
	}
}
