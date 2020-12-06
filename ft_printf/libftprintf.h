/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:58:25 by mel-hadj          #+#    #+#             */
/*   Updated: 2019/12/28 22:20:01 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *ft_phextos(unsigned long int n, int i);
char *ft_uinttos(unsigned int n);
char *ft_ctos(char c);
char *ft_cv(char p, va_list ap, int k);
int ft_flag(const char **l, va_list ap, int dot, int z);
char *ft_hextos(unsigned int n, char c);
char *ft_itoa(int n);
char *ft_sp_string(int a, int b, char *s, int o);
char *ft_sp_ze(int a, int b, char *s, char o);
char *ft_strdup(const char *s1);
char *ft_strjoin(char *s1, char *s2);
char *ft_tolower(char *c);
char *fucking_star(int nu1, char *ptr);
char *func1(int a, int b, char *s);
char *func2(int a, int b, char *s);
char *func3(int b, char *s);
int hadihia(char p, int nu1, int nu2, va_list ap);
char *unique(int nu1, char *ptr);

int check_c(va_list ap, const char **s);
int calci(unsigned long int nb);
int ft_atoi(const char **str, va_list ap);
int ft_ft_atoi(const char *str);
int ft_isflag(char p);
int ft_printf(const char *fmt, ...);
int ft_strlen(const char *s);

size_t ft_putstr(char *str);

void *ft_calloc(size_t count, size_t size);
void ft_bzero(void *s, size_t n);
