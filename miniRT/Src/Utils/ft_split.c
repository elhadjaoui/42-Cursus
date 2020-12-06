/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:54:15 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/08 22:40:16 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/minirt.h"

#include "../../Headers/get_next_line.h"

static	int			nword(char *s, int c)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (*s)
	{
		i++;
		if (((*(s + 1) != c && *s == c && *(s + 1) != '\0')) ||
				(i == 1 && s[0] != c))
			k++;
		s++;
	}
	return (k);
}

static	void		*ft_free(char ***ptr, int i)
{
	char **tmp;

	tmp = *ptr;
	while (i >= 0)
	{
		free(tmp[i]);
		i--;
	}
	return (NULL);
}

static	int			lword(char *s, int c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char				**ft_split(char const *s, char c)
{
	char	**w;
	char	*ptr;
	int		i;
	int		j;
	int		u;

	ptr = (char*)s;
	i = -1;
	if (!(w = (char **)malloc(sizeof(char *) * (nword((char *)s, c) + 1))))
		return (NULL);
	while (++i < nword(ptr, c))
	{
		if (!(w[i] = (char *)ft_calloc((lword((char*)s, c) + 1), sizeof(char))))
			return (ft_free(&w, i));
		j = 0;
		u = lword((char*)s, c);
		while (j < u)
		{
			while (*s != c && *s != '\0')
				w[i][j++] = *s++;
			s++;
		}
	}
	w[i] = NULL;
	return (w);
}
