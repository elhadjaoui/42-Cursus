/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:15:52 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 11:16:02 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

double		getnorm(double x, double y, double z)
{
	return (x * x + y * y + z * z);
}

double		getnorm2(t_vector x, t_vector y)
{
	return (sqrt((pow(y.x - x.x, 2) + pow(y.y * x.y, 2) + pow(y.z * x.z, 2))));
}

t_vector	cross(t_vector vec1, t_vector vec2)
{
	return ((t_vector){
		vec1.y * vec2.z - vec2.y * vec1.z,
		vec2.x * vec1.z - vec1.x * vec2.z,
		vec1.x * vec2.y - vec2.x * vec1.y});
}

t_vector	vec_div_num(t_vector vec, double num)
{
	vec.x /= num;
	vec.y /= num;
	vec.z /= num;
	return (vec);
}

t_vector	invec(t_vector vec)
{
	return ((t_vector){-vec.x, -vec.y, -vec.z});
}
