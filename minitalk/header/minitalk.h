#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	check_if_integer(char *s);
void	print_char(char c);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif