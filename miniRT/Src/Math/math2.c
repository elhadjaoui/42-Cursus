/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 11:22:29 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 11:22:31 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void	normalize(t_vector *p)
{
	double norm;

	norm = sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
	if (norm == 0.0)
		norm = 1.0;
	p->x /= norm;
	p->y /= norm;
	p->z /= norm;
}

void	norm(double *x, double *y, double *z)
{
	double norm;

	norm = sqrt(getnorm(*x, *y, *z));
	*x /= norm;
	*y /= norm;
	*z /= norm;
}
