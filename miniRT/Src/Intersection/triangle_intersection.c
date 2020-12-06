/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:52:07 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 10:52:12 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double		g_t;
double		g_u;
double		g_v;

double		intersection_triangle(t_triangle *tr, t_vector origine,
	t_vector direction)
{
	t_vector	h;
	t_vector	q;
	double		det;
	double		f;
	t_vector	s;

	h = cross(direction, tr->b);
	det = dot(tr->a, h);
	if (det > -0.0000001 && det < 0.0000001)
		return (-2);
	f = 1 / det;
	s = sub_vec(origine, tr->vertex0);
	g_u = f * dot(s, h);
	if (g_u < 0 || g_u > 1)
		return (-6);
	q = cross(s, tr->a);
	g_v = f * dot(direction, q);
	if (g_v < 0 || g_u + g_v > 1)
		return (-3);
	g_t = f * dot(tr->b, q);
	return (g_t);
}

void		closet_tr(t_triangle *tr, t_vector origine,
	t_vector direction, int which)
{
	double t;

	t = intersection_triangle(tr, origine, direction);
	if (t > 0 && t < g_info->h_point)
	{
		if (which == 0)
		{
			g_info->primary_ray = add_vec(origine,
				mult_vec(direction, t));
			g_info->normal = tr->c;
			g_info->obj_color = tr->color;
			g_info->obj_id = tr->id;
		}
		g_info->h_point = t;
		if (which == 1 && g_info->obj_id == tr->id)
			g_info->h_point = 0;
	}
}
