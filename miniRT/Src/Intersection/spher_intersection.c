/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spher_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:23:22 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 10:23:26 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double	intersection_spher(t_spher *sp, t_vector origine, t_vector direction)
{
	double b;
	double c;
	double d;
	double s[2];
	double t;

	b = 2 * dot(direction, sub_vec(origine, sp->origin));
	c = dot(sub_vec(origine, sp->origin), sub_vec(origine,
		sp->origin)) - pow(sp->rayon, 2);
	d = (b * b) - (4 * c);
	if (d < 0)
		return (0);
	s[0] = (-b - sqrt(d)) / 2;
	s[1] = (-b + sqrt(d)) / 2;
	if (s[1] < 0)
		return (0);
	if (s[0] > 0)
		t = s[0];
	else
		t = s[1];
	return (t);
}

void	closet_sp(t_spher *sp, t_vector origine, t_vector direction, int which)
{
	double t;

	t = intersection_spher(sp, origine, direction);
	if (t > 0 && t < g_info->h_point)
	{
		if (which == 0)
		{
			g_info->primary_ray = add_vec(origine,
				mult_vec(direction, t));
			g_info->normal = sub_vec(g_info->primary_ray,
				sp->origin);
			g_info->obj_color = sp->color;
			g_info->obj_id = sp->id;
			normalize(&g_info->normal);
		}
		g_info->h_point = t;
		if (which == 1 && g_info->obj_id == sp->id)
			g_info->h_point = 0;
	}
}
