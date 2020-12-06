/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:24:36 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 11:24:38 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void		plan_full(char **p)
{
	t_plane *plan;

	plan = malloc(sizeof(t_plane));
	if (len_of(p) != 4)
	{
		free_list(p);
		print_error("Plane");
	}
	plan->origin = check_vec(p[1]);
	plan->normal = check_normal(p[2]);
	normalize(&plan->normal);
	plan->color = check_rgb(p[3]);
	plan->id = ++g_x;
	lstadd_obj_back(&g_obj, lstnew_obj(plan, "pl"));
	free_list(p);
}

void		spher_full(char **p)
{
	t_spher *spher;

	spher = malloc(sizeof(t_spher));
	if (len_of(p) != 4)
	{
		free_list(p);
		print_error("Spher");
	}
	spher->origin = check_vec(p[1]);
	if (valid_single_num(p[2]) != 1 || str_f(p[2]) < 0)
	{
		free_list(p);
		print_rayon_error();
	}
	spher->rayon = str_f(p[2]);
	spher->color = check_rgb(p[3]);
	spher->id = ++g_x;
	lstadd_obj_back(&g_obj, lstnew_obj(spher, "sp"));
	free_list(p);
}

void		square_full(char **p)
{
	t_square *sq;

	sq = malloc(sizeof(t_square));
	if (len_of(p) != 5)
	{
		free_list(p);
		print_error("Square");
	}
	sq->origine = check_vec(p[1]);
	sq->normal = check_normal(p[2]);
	normalize(&sq->normal);
	if (valid_single_num(p[3]) != 1 || str_f(p[3]) < 0)
	{
		free_list(p);
		print_sqsize_error();
	}
	sq->size = str_f(p[3]);
	sq->color = check_rgb(p[4]);
	sq->id = ++g_x;
	lstadd_obj_back(&g_obj, lstnew_obj(sq, "sq"));
	free_list(p);
}

void		cylindre_full(char **p)
{
	t_cylindre *cy;

	if (!(cy = malloc(sizeof(t_cylindre))) && len_of(p) != 6)
	{
		free_list(p);
		print_error("Cylindre");
	}
	cy->coord = check_vec(p[1]);
	cy->normal = check_normal(p[2]);
	normalize(&cy->normal);
	cy->color = check_rgb(p[5]);
	if (valid_single_num(p[3]) != 1 || str_f(p[3]) < 0)
	{
		free_list(p);
		print_cyraduis_error();
	}
	if ((valid_single_num(p[4]) != 1 || str_f(p[4]) < 0) && (cy->id = ++g_x))
	{
		free_list(p);
		print_cyheigth_error();
	}
	cy->raduis = str_f(p[3]) / 2.0;
	cy->height = str_f(p[4]);
	lstadd_obj_back(&g_obj, lstnew_obj(cy, "cy"));
	free_list(p);
}

void		triangle_full(char **p)
{
	t_triangle *triangle;

	triangle = malloc(sizeof(t_triangle));
	if (len_of(p) != 5)
	{
		print_error(p[0]);
		free_list(p);
	}
	triangle->vertex0 = check_vec(p[1]);
	triangle->vertex1 = check_vec(p[2]);
	triangle->vertex2 = check_vec(p[3]);
	triangle->a = sub_vec(triangle->vertex1, triangle->vertex0);
	triangle->b = sub_vec(triangle->vertex2, triangle->vertex0);
	triangle->c = cross(triangle->b, triangle->a);
	normalize(&triangle->c);
	triangle->color = check_rgb(p[4]);
	triangle->id = ++g_x;
	lstadd_obj_back(&g_obj, lstnew_obj(triangle, "tr"));
	free_list(p);
}
