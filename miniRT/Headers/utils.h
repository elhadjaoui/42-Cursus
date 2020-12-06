/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:49:07 by mel-hadj          #+#    #+#             */
/*   Updated: 2020/11/29 18:50:27 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"

int			cmp(char *s1, char *s2);
double		str_f(char *str);
int			ft_atoi(const char *str);
int			len_of(char **p);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
void		free_list(char **list);
t_vector	invec(t_vector vec);
size_t		len(const char *s);
#endif
