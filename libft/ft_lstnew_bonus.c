/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:40:54 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/14 17:11:49 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
