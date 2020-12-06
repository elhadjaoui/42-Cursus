/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:46:21 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/11/21 16:17:58 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

int		get_next_line(int fc, char **line);
char	*dpl(char *s1);
char	*join(char *s1, char *s2);
char	*sone(char *s);
char	*stwo(char *s);
size_t	len(const char *s);
#endif
