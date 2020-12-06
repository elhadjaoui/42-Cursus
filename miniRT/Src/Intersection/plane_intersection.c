/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:19:31 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 10:19:44 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

int		intersection_plane(t_plane *pl, t_vector origine, t_vector direction)
{
	float	t;
	float	denom;

	denom = dot(pl->normal, direction);
	if (denom != 0)
	{
		t = dot(sub_vec(pl->origin, origine), pl->normal) / denom;
		return (t);
	}
	return (0);
}

void	closet_pl(t_plane *pl, t_vector origine, t_vector direction, int which)
{
	double t;

	t = intersection_plane(pl, origine, direction);
	if (t > 0 && t < g_info->h_point)
	{
		if (which == 0)
		{
			g_info->primary_ray = add_vec(origine,
				mult_vec(direction, t));
			g_info->obj_color = pl->color;
			g_info->obj_id = pl->id;
			g_info->normal = pl->normal;
		}
		g_info->h_point = t;
		if (which == 1 && g_info->obj_id == pl->id)
			g_info->h_point = 0;
	}
}
