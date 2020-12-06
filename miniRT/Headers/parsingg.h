/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingg.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:17:28 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 13:17:41 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSINGG_H
# define PARSINGG_H

# include "minirt.h"

typedef struct		s_data
{
	int		zoom;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
	t_cam	*cam_first;
}					t_data;

typedef struct		s_obj
{
	void			*content;
	struct s_obj	*next;
	char			*id;
}					t_obj;

void				lstadd_cam_back(t_cam **alst, t_cam *new);
t_cam				*lstnew_cam(t_camera *camera);
t_lights			*lstnew_light(t_light *light);
void				lstadd_light_back(t_lights **alst, t_lights *new);
void				lstadd_obj_back(t_obj **alst, t_obj *new);
t_obj				*lstnew_obj(void *content, char *id);
void				read_file(int fd, t_data *dt);
void				implement_config(char **p, t_data *dt);
void				implement_obj(char **p);
void				plan_full(char **p);
void				spher_full(char **p);
void				square_full(char **p);
void				cylindre_full(char **p);
void				triangle_full(char **p);
void				resol_full(char **p, t_data *dt);
void				ambient_full(char **p);
void				camera_full(char **p);
void				light_full(char **p);
#endif
