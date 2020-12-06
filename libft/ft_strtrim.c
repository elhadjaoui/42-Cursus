/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:43:33 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/10 11:22:05 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	suf(char const *s1, char const *set)
{
	int i;
	int j;
	int k;
	int h;

	i = (int)ft_strlen(set);
	j = 0;
	h = 0;
	k = (int)ft_strlen(s1);
	while (j <= i)
	{
		if (s1[k] == set[j] && k)
		{
			--k;
			j = 0;
		}
		else
		{
			j++;
			h = k;
		}
	}
	return (h);
}

static	int	pref(char const *s1, char const *set)
{
	int i;
	int j;
	int k;
	int h;

	i = ft_strlen(set);
	j = 0;
	k = 0;
	h = 0;
	while (j <= i)
	{
		if ((k <= (int)ft_strlen(s1)) && s1[k] == set[j])
		{
			++k;
			j = 0;
		}
		else
		{
			j++;
			h = k;
		}
	}
	return (h);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*p;

	i = 0;
	start = pref(s1, set);
	end = suf(s1, set);
	if (start >= (int)ft_strlen(s1))
		return (ft_strdup(""));
	if (!(p = (char *)malloc(end - start + 2)))
		return (NULL);
	while (start <= end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
