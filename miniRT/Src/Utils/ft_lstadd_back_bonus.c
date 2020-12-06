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

#include "../../Headers/minirt.h"

void	lstadd_cam_back(t_cam **alst, t_cam *new)
{
	t_cam *last;

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

void	lstadd_light_back(t_lights **alst, t_lights *new)
{
	t_lights *last;

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

void	lstadd_obj_back(t_obj **alst, t_obj *new)
{
	t_obj *last;

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
