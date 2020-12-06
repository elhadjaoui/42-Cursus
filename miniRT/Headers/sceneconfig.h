/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneconfig.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:16:52 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 18:16:54 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENECONFIG_H
# define SCENECONFIG_H

# include "vector.h"

typedef struct			s_camera
{
	int			id;
	t_vector	origine;
	t_vector	direction;
	t_vector	norma;
	t_vector	u;
	t_vector	v;
	double		fov;
}						t_camera;

typedef struct			s_light
{
	int			id;
	t_vector	origine;
	t_rgb		color;
	double		coe;
}						t_light;

typedef struct			s_lights
{
	t_light				*light;
	struct s_lights		*next;
}						t_lights;

typedef struct			s_cam
{
	t_camera		*cam;
	struct s_cam	*next;
}						t_cam;
#endif
