/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:29:01 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 18:29:04 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

t_vector	g_vec;

int				valid_single_int(char *s)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (s[i] == '+')
			i++;
		if (!(s[i] > '/' && s[i] < ':'))
			return (-1);
		i++;
	}
	return (1);
}

int				valid_int(char **s)
{
	int		i;
	int		j;

	i = 0;
	while (i < len_of(s))
	{
		j = 0;
		if (s[i][j] == '+')
			j++;
		while (s[i][j])
		{
			if (!(s[i][j] > '/' && s[i][j] < ':'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

t_rgb			check_rgb(char *s)
{
	char	**sub;
	t_rgb	color;

	sub = ft_split(s, ',');
	if (len_of(sub) != 3)
	{
		free_list(sub);
		print_colorformat_error();
	}
	if (valid_int(sub) == -1)
	{
		free_list(sub);
		print_rgb_error();
	}
	color.r = ft_atoi(sub[0]);
	color.g = ft_atoi(sub[1]);
	color.b = ft_atoi(sub[2]);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 ||
	color.b < 0 || color.b > 255)
	{
		free_list(sub);
		print_rgb_error();
	}
	free_list(sub);
	return (color);
}

t_vector		check_vec(char *s)
{
	char		**sub;
	t_vector	vec;

	sub = ft_split(s, ',');
	if (len_of(sub) != 3)
	{
		ft_putstr_fd("Error\nWrong VECTOR format\n", 0);
		free_list(sub);
		exit(-1);
	}
	if (valid_num(sub) == -1)
	{
		ft_putstr_fd("Error\nWrong VECTOR values\n", 0);
		free_list(sub);
		exit(-1);
	}
	vec.x = str_f(sub[0]);
	vec.y = str_f(sub[1]);
	vec.z = str_f(sub[2]);
	free_list(sub);
	return (vec);
}

t_vector		check_normal(char *s)
{
	char	**sub;

	sub = ft_split(s, ',');
	if (len_of(sub) != 3)
	{
		ft_putstr_fd("Error\nWrong VECTOR NORMAL format\n", 2);
		free_list(sub);
		exit(-1);
	}
	if (valid_num(sub) == -1)
	{
		free_list(sub);
		print_normalvalue_error();
	}
	g_vec.x = str_f(sub[0]);
	g_vec.y = str_f(sub[1]);
	g_vec.z = str_f(sub[2]);
	if (g_vec.x < -1 || g_vec.x > 1 || g_vec.y < -1 || g_vec.y > 1 ||
	g_vec.z < -1 || g_vec.z > 1)
	{
		free_list(sub);
		print_normalvalue_error();
	}
	free_list(sub);
	return (g_vec);
}
