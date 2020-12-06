/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:14:23 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 11:14:25 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

t_vector	sub_vec(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vector	add_vec(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vector	mult_vec(t_vector v1, double v2)
{
	return ((t_vector){v1.x * v2, v1.y * v2, v1.z * v2});
}

t_vector	multiplicatio_vec(t_vector v1, t_vector v2)
{
	return ((t_vector){v1.x * v2.x, v1.y * v2.y, v1.z * v2.z});
}

double		dot(t_vector ray_d, t_vector p2)
{
	return (ray_d.x * p2.x + ray_d.y * p2.y + ray_d.z * p2.z);
}
