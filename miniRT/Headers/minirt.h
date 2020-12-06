/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:40:14 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 11:49:01 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx_mms/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "errors.h"
# include "vector.h"
# include "scene.h"
# include "sceneconfig.h"
# include "parsingg.h"
# include "utils.h"

int						g_width;
int						g_height;
int						g_am;
int						g_ca;
int						g_re;
int						g_x;

typedef struct			s_header
{
	char	tag[2];
	int		filesize;
	short	reserved1;
	short	reserved2;
	int		offset;
	int		infoheader;
	int		width;
	int		heigth;
	short	plane;
	short	bpp;
	int		compression;
	int		image_size;
	int		h_res;
	int		v_res;
	int		n_colors;
	int		n_imp_col;
}						t_header;

typedef struct			s_intersect_info
{
	double		h_point;
	t_vector	primary_ray;
	t_vector	normal;
	t_rgb		obj_color;
	double		shadow;
	t_vector	shadow_ray;
	t_vector	shadow_p;
	int			obj_id;
}						t_intersect_info;

t_cam					*g_c;
t_lights				*g_l;
t_obj					*g_obj;
t_intersect_info		*g_info;
float					g_ambient_coe;
t_rgb					g_ambient_col;

void					ft_draw(t_data *dt);
double					dot(t_vector ray_d, t_vector p2);
t_vector				cross(t_vector vec1, t_vector vec2);
double					getnorm(double x, double y, double z);
void					normalize(t_vector *p);
t_vector				sub_vec(t_vector v1, t_vector v2);
t_vector				add_vec(t_vector v1, t_vector v2);
t_vector				mult_vec(t_vector v1, double v2);
void					save(char *s);
t_rgb					clorify(t_vector cam_origine, t_vector cam_direction);
double					get_color(t_vector cam_origine, t_vector cam_direction,
	int which);
#endif
