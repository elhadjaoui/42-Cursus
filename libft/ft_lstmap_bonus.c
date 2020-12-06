/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:10:21 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 20:05:03 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *p;
	t_list *k;

	k = NULL;
	while (lst && f)
	{
		if (!(p = ft_lstnew((f)(lst->content))))
		{
			ft_lstclear(&k, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&k, p);
		lst = lst->next;
	}
	return (k);
}
