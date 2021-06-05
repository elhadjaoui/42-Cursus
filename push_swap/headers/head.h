/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:34:30 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/06/01 11:34:32 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

void	ft_putstr_fd(char *s, int fd);
void	display(t_list *stack);
void	display_chunk(t_list *stack);
int		cmp(char *s1, char *s2);
char	*ft_sub(char *string);
int		ft_free(t_list **ptr);
void	swap_stack(t_list **stack);
void	pop(t_list **stack);
void	push_front(t_list **stack, int content);
void	push_back(t_list **stack, int content);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_stack(t_list **stack);
void	reverse_rotate_stack(t_list **stack);
void	check_which_operation(char **op, t_list **stack_a, t_list **stack_b);
void	check_stack_is_sorted(t_list **stack_a, t_list **stack_b);
void	check_if_integer(char *s);
void	check_duplicate(char *s, t_list *stack);
int		GetNth(t_list *head, int content);
t_list	*create_stack(int argc, char **argv);
void	freeList(t_list *head);
void	fill_numbers(int *numbers, t_list *slack);
void	quicksort(int *numbers, int first, int last);
int		get_last_in_stack(int p, t_list *head);
int		check_if_sorted(t_list **stack_a);
void	get_content2top_of_stack_reverse(t_list **stack, int content, char *op);
void	fill_numbers(int *numbers, t_list *stack);
int		equal_number_in_chunk(t_list *stack_a, t_list *chunk);
int		get_content(t_list *stack_a, t_list *chunk);
void	send_back2stack_a(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rra(t_list **stack);
void	sa(t_list **stack);
void	sorte_3_number(t_list **stack_a);
void	get_content2top_of_stack(t_list **stack, int content, char *op);
void	get_sorted_list(int *numbers, t_list *stack);
int		get_big_num(t_list *stack);
void	check_max_int(char *str);

#endif
