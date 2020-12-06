/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:33:57 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/12/05 12:33:59 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/minirt.h"

void	fill_header(t_header *header)
{
	header->tag[0] = 'B';
	header->tag[1] = 'M';
	header->filesize = 54 + g_height * g_width * 4;
	header->reserved1 = 0;
	header->reserved2 = 0;
	header->offset = 54;
	header->infoheader = 40;
	header->width = g_width;
	header->heigth = g_height;
	header->plane = 1;
	header->bpp = 32;
	header->compression = 0;
	header->image_size = 0;
	header->h_res = 0;
	header->v_res = 0;
	header->n_colors = 0;
	header->n_imp_col = 0;
}

void	header_tofile(int fp, t_header *header)
{
	write(fp, &(header->tag), 2);
	write(fp, &(header->filesize), 4);
	write(fp, &(header->reserved1), 2);
	write(fp, &(header->reserved2), 2);
	write(fp, &(header->offset), 4);
	write(fp, &(header->infoheader), 4);
	write(fp, &(header->width), 4);
	write(fp, &(header->heigth), 4);
	write(fp, &(header->plane), 2);
	write(fp, &(header->bpp), 2);
	write(fp, &(header->compression), 4);
	write(fp, &(header->image_size), 4);
	write(fp, &(header->h_res), 4);
	write(fp, &(header->v_res), 4);
	write(fp, &(header->n_colors), 4);
	write(fp, &(header->n_imp_col), 4);
}

void	save(char *s)
{
	int			y;
	int			x;
	int			position;
	int			fp;
	t_header	header;

	fill_header(&header);
	fp = open("miniRT.bmp", O_CREAT | O_TRUNC | O_WRONLY, 0666);
	y = g_height - 1;
	header_tofile(fp, &header);
	while (y >= 0)
	{
		x = 0;
		while (x < g_width)
		{
			position = 4 * (x + g_width * y);
			write(fp, (unsigned int *)(s + position), 4);
			x++;
		}
		y--;
	}
	close(fp);
	ft_putstr_fd("file seved as 'miniRT.bmp'\n", 2);
	exit(EXIT_SUCCESS);
}
