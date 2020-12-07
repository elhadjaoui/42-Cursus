/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:46:36 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/30 18:46:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

int		cmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1 && !*s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

int		len_of(char **p)
{
	int i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

int		free_list(char **list)
{
	int i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	return (1);
}

int		valid_num(char **s)
{
	int i;
	int j;
	int d;

	i = 0;
	d = 0;
	while (i < len_of(s))
	{
		j = 0;
		d = 0;
		if (s[i][j] == '+' || s[i][j] == '-')
			j++;
		while (s[i][j])
		{
			if (s[i][j] != '.' && !(s[i][j] > '/' && s[i][j] < ':'))
				return (-1);
			if (s[i][j] == '.')
				d++;
			if (d >= 2)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		valid_single_num(char *s)
{
	int i;
	int d;

	i = 0;
	d = 0;
	while (s[i])
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (s[i] != '.' && !(s[i] > '/' && s[i] < ':'))
			return (-1);
		if (s[i] == '.')
			d++;
		if (d >= 2)
			return (-1);
		i++;
	}
	return (1);
}
