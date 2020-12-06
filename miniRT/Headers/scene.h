/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:08:50 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 18:08:52 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "vector.h"

typedef struct			s_spher
{
	int			id;
	t_vector	origin;
	t_rgb		color;
	double		rayon;
}						t_spher;

typedef struct			s_triangle
{
	int			id;
	t_vector	vertex1;
	t_vector	vertex2;
	t_vector	vertex0;
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_rgb		color;
}						t_triangle;

typedef struct			s_cylinder
{
	int			id;
	t_vector	coord;
	t_vector	coord2;
	t_vector	normal;
	double		raduis;
	double		height;
	t_rgb		color;
}						t_cylindre;

typedef struct			s_square
{
	int			id;
	t_vector	origine;
	t_vector	normal;
	double		size;
	t_rgb		color;
}						t_square;

typedef struct			s_plane
{
	int			id;
	t_vector	origin;
	t_rgb		color;
	t_vector	normal;
}						t_plane;

void					closet_cy(t_cylindre *cy, t_vector origine,
	t_vector direction, int which);
void					closet_pl(t_plane *pl, t_vector origine,
	t_vector direction, int which);
void					closet_sp(t_spher *sp,
	t_vector origine, t_vector direction, int which);
void					closet_sq(t_square *sq,
	t_vector origine, t_vector direction, int which);
void					closet_tr(t_triangle *tr,
	t_vector origine, t_vector direction, int which);
#endif
