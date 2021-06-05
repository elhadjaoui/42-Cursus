/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:21:08 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:21:10 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/head.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	display_chunk(t_list *stack)
{
	t_list	*new_stack;

	new_stack = stack;
	if (new_stack)
	{
		while (new_stack->next != NULL)
		{
			write(0, ft_itoa(new_stack->chunk),
				ft_strlen(ft_itoa(new_stack->chunk)));
			write(0, "\n", 1);
			new_stack = new_stack->next;
		}
		write(0, ft_itoa(new_stack->chunk),
			ft_strlen(ft_itoa(new_stack->chunk)));
		write(0, "\n", 1);
	}
	else
		ft_putstr_fd("this stack is empty\n", 1);
}

void	display(t_list *stack)
{
	t_list	*new_stack;

	new_stack = stack;
	if (new_stack)
	{
		while (new_stack->next != NULL)
		{
			write(0, ft_itoa(new_stack->content),
				ft_strlen(ft_itoa(new_stack->content)));
			write(0, " - ", 3);
			write(0, ft_itoa(new_stack->chunk),
				ft_strlen(ft_itoa(new_stack->chunk)));
			write(0, "\n", 1);
			new_stack = new_stack->next;
		}
		write(0, ft_itoa(new_stack->content),
			ft_strlen(ft_itoa(new_stack->content)));
		write(0, " - ", 3);
		write(0, ft_itoa(new_stack->chunk),
			ft_strlen(ft_itoa(new_stack->chunk)));
		write(0, "\n", 1);
	}
	else
		ft_putstr_fd("this stack is empty\n", 1);
}

int	cmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1 && !*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

// ft_sub check if the string has a \n and retunrn the string  without it

char	*ft_sub(char *string)
{
	char	*baby;
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	if (string == NULL)
	{
		baby = malloc(1);
		if (!baby)
			return (NULL);
		baby[0] = 0;
		return (baby);
	}
	while (string[x] != '\0' && string[x] != '\n')
		x++;
	baby = malloc(x + 1);
	baby[x] = '\0';
	while (y < x)
	{
		baby[y] = string[y];
		y++;
	}
	return (baby);
}
