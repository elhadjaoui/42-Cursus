/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:19 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:22 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	pop(t_list **stack)
{
	t_list	*new_stack;

	new_stack = *stack;
	if (*stack)
	{
		*stack = (*stack)->next;
		ft_free(&new_stack);
	}
}

void	push_front(t_list **stack, int content)
{
	ft_lstadd_front(stack, ft_lstnew(content));
}

void	push_back(t_list **stack, int content)
{
	ft_lstadd_back(stack, ft_lstnew(content));
}

int	GetNth(t_list *head, int content)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (current->content == content)
			return (count);
		count++;
		current = current->next;
	}
	if (count >= ft_lstsize(head))
		return (0);
	return (count);
}

t_list	*create_stack(int argc, char **argv)
{
	int		i;
	t_list	*stack;

	if (argc <= 1)
		exit(1);
	i = 1;
	stack = NULL;
	while (i < argc)
	{
		check_if_integer(argv[i]);
		check_max_int(argv[i]);
		check_duplicate(argv[i], stack);
		ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (stack);
}
