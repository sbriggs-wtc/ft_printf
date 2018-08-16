/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:52:20 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/16 10:42:13 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
#include <stdio.h>
#define FMT "sSpdDioOuUxXcC%"

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
		if (*(format + i) == '%' && *(format + i + 1) != '\0')
		{
			i++;
			ret += pr_format((format + i), ap);
			if (ret == -1)
				return (0);
			while (!pr_strchr(FMT, *(format + i)) && *(format + i) != '\0')
				i++;
		}
		else if (*(format + i) != '%' && *(format + i) != '\0')
			ret += pr_putchar(*(format + i));
		i++;
	}
	va_end(ap);
	return (ret);
}
