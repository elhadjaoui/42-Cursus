/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:15:08 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 11:39:37 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "minirt.h"
# include "vector.h"

void		print_error(char *s);
void		print_re_error(char *s);
void		print_am_error(char *s);
void		print_ca_error();
void		print_fov_error();
void		print_intensity_error();
void		print_intruder_error();
void		print_rayon_error();
void		print_cyraduis_error();
void		print_cyheigth_error();
void		print_sqsize_error();
void		print_colorformat_error();
void		print_normalvalue_error();
void		print_random_error();
t_rgb		check_rgb(char *s);
t_vector	check_vec(char *s);
void		print_rgb_error();
t_vector	check_normal(char *s);
int			valid_int(char **s);
int			valid_num(char **s);
int			valid_single_num(char *s);
int			valid_single_int(char *s);
#endif
