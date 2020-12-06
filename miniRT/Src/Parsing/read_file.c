/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 21:57:26 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/03/09 21:57:28 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"
#include "../../Headers/get_next_line.h"

char	**g_p;

void		check_scene(void)
{
	if (g_re == 0)
		print_re_error("Resoution");
	if (g_am == 0)
		print_am_error("Ambient");
	if (g_ca == 0)
		print_ca_error();
}

void		read_file(int fd, t_data *dt)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (*line == '\0')
		{
			free(line);
			continue;
		}
		g_p = ft_split(line, ' ');
		if (*g_p == NULL)
			print_intruder_error();
		implement_config(g_p, dt);
		free(line);
	}
	if (*line != '\0')
	{
		g_p = ft_split(line, ' ');
		implement_config(g_p, dt);
		free(line);
	}
	else
		free(line);
	check_scene();
}

void		implement_config(char **p, t_data *dt)
{
	if (cmp(*p, "R"))
	{
		++g_re;
		resol_full(p, dt);
	}
	else if (cmp(*p, "A"))
	{
		++g_am;
		ambient_full(p);
	}
	else if (cmp(*p, "c"))
	{
		++g_ca;
		camera_full(p);
	}
	else if (cmp(*p, "l"))
		light_full(p);
	else
		implement_obj(p);
}

void		implement_obj(char **p)
{
	if (cmp(*p, "pl"))
		plan_full(p);
	else if (cmp(*p, "sp"))
		spher_full(p);
	else if (cmp(*p, "tr"))
		triangle_full(p);
	else if (cmp(*p, "sq"))
		square_full(p);
	else if (cmp(*p, "cy"))
		cylindre_full(p);
	else
	{
		if (cmp(*p, "#") != 1)
		{
			free_list(p);
			print_intruder_error();
		}
		free_list(p);
	}
}
