/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:47:38 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 20:47:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double		intersection_cy(t_cylindre *cy, t_vector origine,
	t_vector direction)
{
	double		a[4];
	double		s[3];
	t_vector	p[4];

	a[0] = 1 - pow(dot(cy->normal, direction), 2);
	p[3] = sub_vec(origine, cy->coord);
	a[1] = dot(p[3], direction) - (dot(p[3], cy->normal)
	* dot(direction, cy->normal));
	a[2] = dot(p[3], p[3]) - pow(dot(p[3], cy->normal), 2) - pow(cy->raduis, 2);
	a[3] = a[1] * a[1] - (a[0] * a[2]);
	if (a[3] < 0)
		return (-1);
	s[0] = (-a[1] - sqrt(a[3])) / a[0];
	s[1] = (-a[1] + sqrt(a[3])) / a[0];
	if (s[1] < 0.00000001)
		return (-1);
	p[0] = add_vec(origine, mult_vec(direction, s[0]));
	p[1] = add_vec(origine, mult_vec(direction, s[1]));
	if (fabs(dot(cy->normal, sub_vec(p[0], cy->coord))) <= cy->height)
		s[2] = s[0];
	else if (fabs(dot(cy->normal, sub_vec(p[1], cy->coord))) <= cy->height)
		s[2] = s[1];
	else
		return (-1);
	return (s[2]);
}

t_vector	get_mormal(t_cylindre *cy, t_vector p)
{
	double		d;
	t_vector	h;
	t_vector	normal;

	d = dot(cy->normal, sub_vec(p, cy->coord));
	h = add_vec(cy->coord, mult_vec(cy->normal, d));
	normal = sub_vec(p, h);
	normalize(&normal);
	return (normal);
}

void		closet_cy(t_cylindre *cy, t_vector origine,
	t_vector direction, int which)
{
	double t;

	t = intersection_cy(cy, origine, direction);
	if (t > 0 && t < g_info->h_point)
	{
		if (which == 0)
		{
			g_info->primary_ray = add_vec(origine,
				mult_vec(direction, t));
			g_info->obj_color = cy->color;
			g_info->obj_id = cy->id;
			g_info->normal = get_mormal(cy,
				g_info->primary_ray);
		}
		g_info->h_point = t;
		if (which == 1 && g_info->obj_id == cy->id)
			g_info->h_point = 0;
	}
}
