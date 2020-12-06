/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:03:24 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 17:03:26 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

void		print_error(char *s)
{
	ft_putstr_fd("Error\nWrong number of informations given to ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void		print_re_error(char *s)
{
	ft_putstr_fd("Error\nWrong informations given to ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Or there's no ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(" Or multiple ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void		print_am_error(char *s)
{
	ft_putstr_fd("Error\nWrong informations given to ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Or there's no ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("Or multiple ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void		print_ca_error(void)
{
	ft_putstr_fd("Error\nthere's no camera ", 2);
	ft_putstr_fd("\n", 2);
	exit(-1);
}

void		print_rgb_error(void)
{
	ft_putstr_fd("Error\nWrong RGB values\n", 2);
	exit(-1);
}
