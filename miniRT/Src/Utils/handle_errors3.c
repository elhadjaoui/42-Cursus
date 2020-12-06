/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:06:48 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 17:06:50 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void	print_cyraduis_error(void)
{
	ft_putstr_fd("Error\nWrong VALUE given to Cylinder Raduis\n", 2);
	exit(-1);
}

void	print_cyheigth_error(void)
{
	ft_putstr_fd("Error\nWrong VALUE given to Cylinder Heigth\n", 2);
	exit(-1);
}

void	print_colorformat_error(void)
{
	ft_putstr_fd("Error\nWrong COLOR format\n", 2);
	exit(-1);
}

void	print_normalvalue_error(void)
{
	ft_putstr_fd("Error\nWrong VECTOR NORMAL values\n", 2);
	exit(-1);
}

void	print_random_error(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("more/fewer arguments than expected\n", 2);
	exit(-1);
}
