/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:04:40 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/09 12:51:09 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(char *format, ...);
void	pr_bzero(void *s, int n);
int		pr_format(char *s, va_list ap);
char	*pr_itoa_base(long n, int base);
int		pr_putchar(char c);
int		pr_putlong(long n);
int		pr_putnbr(int n);
int		pr_putstr(char *s);
int		pr_putstr_case(char *s, int c);
char	*pr_strchr(char *s, int c);
int		pr_tolower(int c);

#endif
