/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:45:02 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/09 16:15:12 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#define FMT "sSpdDioOuUxXcC%"
#define MAX_LONG 4294967296
#define LOWERCASE 1


int		pr_format(char *s, va_list ap)
{
	int		i;
	long	n;
	int		ret;
	int		flagspaces;
	long	p;

	flagspaces = 0;
	ret = 0;
	i = 0;
	while(!(pr_strchr(FMT, *(s + i))) && *(s + i))
		i++;
	if (*(s + i) == '%')
		ret = pr_putchar('%');
	else if (*(s + i) == 'c')
		ret = pr_putchar(va_arg(ap, int));
	else if (*(s + i) == 's')
		ret = pr_putstr(va_arg(ap, char *));
	else if (*(s + i) == 'i' || *(s + i) == 'd')
		ret = pr_putstr(pr_itoa_base(va_arg(ap, int), 10));
	else if (*(s + i) == 'p')
	{
		p = (long)(va_arg(ap, void *));
		ret = pr_putstr("0x");
		ret += pr_putstr_case(pr_itoa_base(p, 16), LOWERCASE);
	}
	else if (*(s + i) == 'u')
	{
		if ((n = va_arg(ap, int)) < 0)
			ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 10));
		else
			ret = pr_putstr(pr_itoa_base(n, 10));
	}
	else if (*(s + i) == 'U')
	{
		if ((n = va_arg(ap, int)) < 0)
			ret = pr_putlong(MAX_LONG + n);
		else
			ret = pr_putlong(n);
	}
	else if (*(s + i) == 'o')
	{
		if ((n = (va_arg(ap, int))) < 0)
			ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 8));
		else
			ret = pr_putstr(pr_itoa_base(n, 8));
	}
	else if (*(s + i) == 'x')
	{
		if ((n = (va_arg(ap, int))) < 0)
			ret = pr_putstr_case(pr_itoa_base(MAX_LONG + n, 16), LOWERCASE);
		else
			ret = pr_putstr_case(pr_itoa_base(n, 16), LOWERCASE);
	}
	else if (*(s + i) == 'X')
	{
		if ((n = (va_arg(ap, int))) < 0)
			ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 16));
		else
			ret = pr_putstr(pr_itoa_base(n, 16));
	}
	return(ret);
}
