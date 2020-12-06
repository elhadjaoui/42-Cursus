/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:27:31 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 10:27:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

t_vector	g_defup;
double		g_t;
double		g_det;
t_vector	g_p;

double		intersection_square(t_square *sq, t_vector origine,
	t_vector direction)
{
	t_vector	edge1;
	t_vector	edge2;
	double		proj1;
	double		proj2;
	t_vector	v;

	g_det = dot(direction, sq->normal);
	if (g_det == 0)
		return (-1);
	g_t = dot(sub_vec(sq->origine, origine), sq->normal) / g_det;
	g_p = add_vec(origine, mult_vec(direction, g_t));
	g_defup = (t_vector){0, 1, 0};
	if (g_defup.x == sq->normal.x && g_defup.y == fabs(sq->normal.y) &&
		g_defup.z == sq->normal.z)
		g_defup = (t_vector){0, 0, 1};
	edge1 = cross(g_defup, sq->normal);
	edge2 = cross(edge1, sq->normal);
	v = sub_vec(g_p, sq->origine);
	proj1 = dot(edge1, v);
	proj2 = dot(edge2, v);
	if (fabs(proj1) < sq->size / 2 && fabs(proj2) < sq->size / 2)
		return (g_t);
	return (-1);
}

void		closet_sq(t_square *sq, t_vector origine,
	t_vector direction, int which)
{
	double t;

	t = intersection_square(sq, origine, direction);
	if (t > 0 && t < g_info->h_point)
	{
		if (which == 0)
		{
			g_info->primary_ray = add_vec(origine,
				mult_vec(direction, t));
			g_info->obj_color = sq->color;
			g_info->obj_id = sq->id;
			g_info->normal = sq->normal;
			if (dot(sq->normal, direction) > 0)
				g_info->normal = invec(g_info->normal);
		}
		g_info->h_point = t;
		if (which == 1 && g_info->obj_id == sq->id)
			g_info->h_point = 0;
	}
}
