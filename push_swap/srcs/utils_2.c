/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:28 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:31 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	swap(int *temp, int *numbers, int i, int j)
{
	*temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = *temp;
}

void	quicksort(int *numbers, int first, int last)
{
	int	pivot;
	int	temp;
	int	j;
	int	i;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (numbers[i] <= numbers[pivot] && i < last)
				i++;
			while (numbers[j] > numbers[pivot])
				j--;
			if (i < j)
				swap(&temp, numbers, i, j);
		}
		temp = numbers[pivot];
		numbers[pivot] = numbers[j];
		numbers[j] = temp;
		quicksort(numbers, first, j - 1);
		quicksort(numbers, j + 1, last);
	}
}

void	freeList(t_list *head)
{
	t_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	get_last_in_stack(int p, t_list *head)
{
	t_list	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (count == p)
			return (current->content);
		count++;
		current = current->next;
	}
	return (current->content);
}
