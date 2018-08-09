/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:52:20 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/06 17:07:03 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include <stdio.h>
#define FMT1 "sSpdDioOuUxXcC%"

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	ret = 0;
	va_start(ap, format);
	i = 0;
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			i++;
			ret += pr_format((format + i), ap);
		}
		else
		{
			ret += pr_putchar(*(format + i));
		}
		i++;
	}
	va_end(ap);
	return(ret);
}
