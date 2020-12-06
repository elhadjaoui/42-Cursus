/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:02:11 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 17:02:14 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void		print_fov_error(void)
{
	ft_putstr_fd("Error\nWrong VALUES given to FOV\n", 2);
	exit(-1);
}

void		print_intensity_error(void)
{
	ft_putstr_fd("Error\nWrong VALUE given to Light Intensity\n", 2);
	exit(-1);
}

void		print_intruder_error(void)
{
	ft_putstr_fd("Error\nIntruder Charachter\n", 2);
	exit(-1);
}

void		print_rayon_error(void)
{
	ft_putstr_fd("Error\nWrong VALUE given to Spher Rayon\n", 2);
	exit(-1);
}

void		print_sqsize_error(void)
{
	ft_putstr_fd("Error\nWrong VALUE given to Square Size\n", 2);
	exit(-1);
}
