/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 11:28:00 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/10/20 18:28:01 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double		g_dt;
double		g_ldotv;
t_vector	g_viewd;
t_vector	g_r;
double		g_k;
t_rgb		g_color;
int			g_position;
double		g_distance;
double		g_angle;
int			g_x;
int			g_y;

t_rgb		calc_spercular(t_vector light_dir, t_rgb color, t_light *light)
{
	g_viewd = mult_vec(light_dir, -1);
	g_k = 2 * dot(g_info->normal, light_dir);
	g_r = sub_vec(mult_vec(g_info->normal, g_k), g_info->normal);
	normalize(&g_r);
	g_ldotv = dot(g_r, g_viewd);
	if (pow(g_ldotv, 40) < 0)
		g_ldotv = 0;
	g_dt = dot(light_dir, g_info->normal);
	if (g_dt < 0)
		g_dt = 0;
	color.r += (light->color.r * light->coe * g_dt) + (light->color.r *
		light->coe * pow(g_ldotv, 40)) + g_info->obj_color.r * light->coe;
	color.g += (light->color.g * light->coe * g_dt) + (light->color.g *
		light->coe * pow(g_ldotv, 40)) + g_info->obj_color.g * light->coe;
	color.b += (light->color.b * light->coe * g_dt) + (light->color.b *
		light->coe * pow(g_ldotv, 40)) + g_info->obj_color.b * light->coe;
	return (color);
}

t_rgb		calc_intensite(void)
{
	t_lights	*first_light;
	t_rgb		color;
	t_vector	light_dir;

	first_light = g_l;
	color.r = g_ambient_col.r * g_ambient_coe + g_info->obj_color.r
		* g_ambient_coe;
	color.g = g_ambient_col.g * g_ambient_coe + g_info->obj_color.g
		* g_ambient_coe;
	color.b = g_ambient_col.b * g_ambient_coe + g_info->obj_color.b
		* g_ambient_coe;
	while (first_light != NULL)
	{
		light_dir = sub_vec(first_light->light->origine, g_info->shadow_ray);
		g_distance = dot(light_dir, light_dir);
		normalize(&light_dir);
		if (first_light->light->coe != 0)
			g_info->shadow = get_color(g_info->shadow_ray, light_dir, 1);
		if (g_info->shadow > 0 && g_info->shadow < sqrt(g_distance) - 0.0000001)
			;
		else
			color = calc_spercular(light_dir, color, first_light->light);
		first_light = first_light->next;
	}
	return (color);
}

double		get_color(t_vector cam_origine, t_vector cam_direction, int which)
{
	t_obj *first_obj;

	first_obj = g_obj;
	g_info->h_point = 1e6;
	while (first_obj != NULL)
	{
		if (cmp(first_obj->id, "sp"))
			closet_sp(first_obj->content, cam_origine, cam_direction, which);
		if (cmp(first_obj->id, "pl"))
			closet_pl(first_obj->content, cam_origine, cam_direction, which);
		if (cmp(first_obj->id, "tr"))
			closet_tr(first_obj->content, cam_origine, cam_direction, which);
		if (cmp(first_obj->id, "sq"))
			closet_sq(first_obj->content, cam_origine, cam_direction, which);
		if (cmp(first_obj->id, "cy"))
			closet_cy(first_obj->content, cam_origine, cam_direction, which);
		first_obj = first_obj->next;
	}
	if (g_info->h_point == 1e6)
		return (-1);
	return (g_info->h_point);
}

t_rgb		clorify(t_vector cam_origine, t_vector cam_direction)
{
	t_rgb	intensite_pixel;
	int		t;

	intensite_pixel = (t_rgb){0, 0, 0};
	t = get_color(cam_origine, cam_direction, 0);
	if (t > 0)
	{
		g_info->shadow_ray = add_vec(g_info->primary_ray,
			mult_vec(g_info->normal, 0.000001));
		intensite_pixel = calc_intensite();
	}
	if (intensite_pixel.r > 255)
		intensite_pixel.r = 255;
	if (intensite_pixel.g > 255)
		intensite_pixel.g = 255;
	if (intensite_pixel.b > 255)
		intensite_pixel.b = 255;
	if (intensite_pixel.r < 0)
		intensite_pixel.r = 0;
	if (intensite_pixel.g < 0)
		intensite_pixel.g = 0;
	if (intensite_pixel.b < 0)
		intensite_pixel.b = 0;
	return (intensite_pixel);
}

void		ft_draw(t_data *dt)
{
	double		x1[2];

	g_y = 0;
	while (g_y < g_height)
	{
		g_x = 0;
		while (g_x < g_width)
		{
			g_angle = tan((g_c->cam->fov / 2) * M_PI / 180);
			x1[0] = (2.0 * ((g_x + 0.5) / (double)g_width) - 1) *
			(g_angle * (double)g_width / (double)g_height);
			x1[1] = (1 - 2.0 * ((g_y + 0.5) / (double)g_height)) * g_angle;
			g_c->cam->direction = add_vec(g_c->cam->norma,
			add_vec(mult_vec(g_c->cam->u, x1[0]),
			mult_vec(g_c->cam->v, x1[1])));
			normalize(&g_c->cam->direction);
			g_position = 4 * (g_x + g_width * g_y);
			g_color = clorify(g_c->cam->origine, g_c->cam->direction);
			dt->img_data[g_position + 2] = g_color.r;
			dt->img_data[g_position + 1] = g_color.g;
			dt->img_data[g_position] = g_color.b;
			g_x++;
		}
		g_y++;
	}
}
