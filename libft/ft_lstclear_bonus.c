/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:53:43 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 15:54:10 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *p;
	t_list *store;

	if (lst != NULL && del != NULL)
	{
		store = *lst;
		while (store != NULL)
		{
			p = store;
			store = store->next;
			(del)(p->content);
			free(p);
		}
		*lst = NULL;
	}
}
