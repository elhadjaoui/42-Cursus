/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:18:55 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 12:18:57 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void	resol_full(char **p, t_data *dt)
{
	int		maxw;
	int		maxy;

	maxy = 0;
	maxw = 0;
	if (len_of(p) != 3)
	{
		free_list(p);
		print_error("Resolution");
	}
	if (valid_single_int(p[1]) != 1 || valid_single_int(p[2]) != 1 || g_re != 1)
	{
		free_list(p);
		print_re_error("Resolut ion");
	}
	g_width = ft_atoi(p[1]);
	g_height = ft_atoi(p[2]);
	mlx_get_screen_size(dt->mlx_ptr, &maxw, &maxy);
	if (g_height > maxy)
		g_height = maxy;
	if (g_width > maxw)
		g_width = maxw;
	free_list(p);
}

void	ambient_full(char **p)
{
	if (len_of(p) != 3)
	{
		free_list(p);
		print_error("A");
	}
	if (valid_single_num(p[1]) != 1)
	{
		free_list(p);
		print_am_error("A");
	}
	g_ambient_coe = str_f(p[1]);
	if (g_ambient_coe < 0 || g_ambient_coe > 1 || g_am != 1)
	{
		free_list(p);
		print_am_error("A");
	}
	g_ambient_col = check_rgb(p[2]);
	free_list(p);
}

void	camera_full(char **p)
{
	t_vector up;
	t_camera *cam;

	up = (t_vector){0, 1, 0};
	cam = malloc(sizeof(t_camera));
	if (len_of(p) != 4)
	{
		free_list(p);
		print_error("Camera");
	}
	cam->origine = check_vec(p[1]);
	cam->norma = check_normal(p[2]);
	if (valid_single_num(p[3]) != 1 || str_f(p[3]) < 0 || str_f(p[3]) > 180)
	{
		free_list(p);
		print_fov_error();
	}
	cam->fov = str_f(p[3]);
	if ((cam->norma.x == 0 && cam->norma.y == 1 && cam->norma.z == 0) ||
		(cam->norma.x == 0 && cam->norma.y == -1 && cam->norma.z == 0))
		up = (t_vector){0, 0, 1};
	cam->u = cross(up, cam->norma);
	cam->v = cross(cam->norma, cam->u);
	lstadd_cam_back(&g_c, lstnew_cam(cam));
	free_list(p);
}

void	light_full(char **p)
{
	t_light *lightt;

	lightt = malloc(sizeof(t_light));
	if (len_of(p) != 4)
	{
		free_list(p);
		print_error("Light");
	}
	lightt->origine = check_vec(p[1]);
	if (valid_single_num(p[2]) != 1 || str_f(p[2]) < 0 || str_f(p[2]) > 1)
	{
		free_list(p);
		print_intensity_error();
	}
	lightt->coe = str_f(p[2]);
	lightt->color = check_rgb(p[3]);
	lightt->id = 0;
	lstadd_light_back(&g_l, lstnew_light(lightt));
	free_list(p);
}
