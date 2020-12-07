/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:56:32 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/03/03 15:46:56 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Headers/minirt.h"

int		g_fd;

int		delay_key(int key, t_data *dt)
{
	dt->zoom = 10;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 49)
	{
		if (g_c->next == NULL)
			g_c = dt->cam_first;
		else
			g_c = g_c->next;
	}
	ft_draw(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
	return (key);
}

int		closered(void)
{
	exit(0);
}

void	check_rt(char *s)
{
	int i;

	if (cmp(s, ".rt") == 1)
	{
		ft_putstr_fd("Error\n'.rt' seems like a hidden file\n", 2);
		exit(-1);
	}
	i = len(s);
	if (!(s[i - 1] == 't') || !(s[i - 2] == 'r') || !(s[i - 3] == '.'))
	{
		ft_putstr_fd("Error\nThe file given isn't in REAL TEXT FORMAT\n", 2);
		ft_putstr_fd("Or ther's no such file\n", 2);
		exit(-1);
	}
}

void	check_save(char *s, t_data *dt)
{
	if (cmp(s, "--save") != 1)
	{
		ft_putstr_fd("Error\ndid you mean '--save'\n", 2);
		exit(-1);
	}
	ft_putstr_fd("saving..\n", 1);
	save(dt->img_data);
}

int		main(int ac, char **av)
{
	t_data	*dt;

	if (ac == 2 || ac == 3)
	{
		g_info = malloc(sizeof(t_intersect_info));
		if ((g_info->h_point = 1e6) && ac == 2)
			check_rt(av[1]);
		dt = malloc(sizeof(t_data));
		dt->mlx_ptr = mlx_init();
		g_fd = open(av[1], O_RDONLY);
		read_file(g_fd, dt);
		dt->mlx_win = mlx_new_window(dt->mlx_ptr, g_width, g_height, "miniRT");
		dt->img_ptr = mlx_new_image(dt->mlx_ptr, g_width, g_height);
		dt->img_data = mlx_get_data_addr(dt->img_ptr, &dt->bpp,
		&dt->size_line, &dt->endian);
		dt->cam_first = g_c;
		ft_draw(dt);
		if (ac == 3)
			check_save(av[2], dt);
		mlx_put_image_to_window(dt->mlx_ptr, dt->mlx_win, dt->img_ptr, 0, 0);
		mlx_key_hook(dt->mlx_win, delay_key, dt);
		mlx_hook(dt->mlx_win, 17, (1L << 17), closered, NULL);
		mlx_loop(dt->mlx_ptr);
	}
	print_random_error();
}
