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

#include "../../Headers/minirt.h"

t_cam		*lstnew_cam(t_camera *camera)
{
	t_cam *p;

	p = malloc(sizeof(t_cam));
	if (p == NULL)
		return (NULL);
	p->cam = camera;
	p->next = NULL;
	return (p);
}

t_lights	*lstnew_light(t_light *light)
{
	t_lights *p;

	p = malloc(sizeof(t_light));
	if (p == NULL)
		return (NULL);
	p->light = light;
	p->next = NULL;
	return (p);
}

t_obj		*lstnew_obj(void *content, char *id)
{
	t_obj *p;

	p = malloc(sizeof(t_obj));
	if (p == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	p->id = id;
	return (p);
}
