/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 17:04:40 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/13 12:11:54 by sbriggs          ###   ########.fr       */
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
int		pr_putaddr(va_list ap);
int		pr_putchar(char c);
int		pr_putstr(char *s);
int		pr_putstr_case(char *s, int c);
char	*pr_strchr(char *s, int c);
int		pr_tolower(int c);
int		pr_toupper(int c);

#endif
