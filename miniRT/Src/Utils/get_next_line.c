/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:25:31 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/22 21:05:38 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/get_next_line.h"

int	sfl(char *p)
{
	while (p != NULL && *p)
	{
		if (*p == '\n')
			return (1);
		p++;
	}
	return (0);
}

int	sfw(char *p)
{
	while (p != NULL && *p)
	{
		if (*p == '\n')
			return (0);
		p++;
	}
	return (1);
}

int	fr(char **p)
{
	free(*p);
	*p = NULL;
	return (1);
}

int	get_next_line(int fd, char **l)
{
	static char	*p;
	char		*b;
	char		*s;
	ssize_t		r;

	if (l == NULL || BUFFER_SIZE < 1 || !(b = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((r = 5) && sfw(p) &&
			(r = read(fd, b, BUFFER_SIZE)) != 0)
	{
		if ((s = p) && r < 0)
			return (-1);
		b[r] = '\0';
		p = join(p, b);
		free(s);
	}
	if (fr(&b) && sfl(p) && r != 0 && (*l = sone(p)) &&
			(s = p) &&
			(p = stwo(p)))
		free(s);
	else if (r != 0)
		*l = sone(p);
	else if (r == 0 && sfw(p) && (*l = dpl(p)) && fr(&p))
		return (0);
	return (1);
}
