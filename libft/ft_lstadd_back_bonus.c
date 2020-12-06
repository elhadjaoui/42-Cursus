/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:43:33 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 17:07:48 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	last = *alst;
	if (!(*alst))
		*alst = new;
	while (last != NULL)
	{
		if (last->next == NULL)
		{
			last->next = new;
			break ;
		}
		last = last->next;
	}
}
