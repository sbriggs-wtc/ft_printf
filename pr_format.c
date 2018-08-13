/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:45:02 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/13 10:40:37 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#define FMT "sSpdDioOuUxXcC%"
#define MAX_LONG 4294967296
#define MAX_LONG_LONG 140733193388032
#define NO_CASE 0
#define LOWERCASE 1
#define UPPERCASE 2

int		pr_chars(va_list ap, char c)
{
	int		ret;

	ret = 0;
	if (c == '%')
		ret = pr_putchar('%');
	if (c == 'c')
		ret = pr_putchar(va_arg(ap, int));
	if (c == 's')
		ret = pr_putstr(va_arg(ap, char *));
	return (ret);
}

int		pr_ints(va_list ap, char c)
{
	int		ret;
	int		n;

	ret = 0;
	n = va_arg(ap, int);
	if (c == 'i' || c == 'd')
		ret = pr_putstr(pr_itoa_base(n, 10));
	else if (c == 'u')
	{
		if (n < 0)
			ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 10));
		else
			ret = pr_putstr(pr_itoa_base(n, 10));
	}
	return (ret);
}

int		pr_bases(va_list ap, char c)
{
	int		ret;
	int		n;

	ret = 0;
	n = va_arg(ap, int);
	if (c == 'o' && n < 0)
		ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 8));
	else if (c == 'o' && n >= 0)
		ret = pr_putstr(pr_itoa_base(n, 8));
	else if (c == 'x' && n < 0)
		ret = pr_putstr_case(pr_itoa_base(MAX_LONG + n, 16), LOWERCASE);
	else if (c == 'x' && n >= 0)
		ret = pr_putstr_case(pr_itoa_base(n, 16), LOWERCASE);
	else if (c == 'X' && n < 0)
		ret = pr_putstr_case(pr_itoa_base(MAX_LONG + n, 16), UPPERCASE);
	else if (c == 'X' && n >= 0)
		ret = pr_putstr_case(pr_itoa_base(n, 16), UPPERCASE);
	return (ret);
}

int		pr_longints(va_list ap, char c)
{
	int		ret;
	int		n;

	ret = 0;
	n = va_arg(ap, long);
	if (c == 'U' && n < 0)
		ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 10));
	else if (c == 'U' && n >= 0)
		ret = pr_putstr(pr_itoa_base(n, 10));
	else if (c == 'O' && n < 0)
		ret = pr_putstr(pr_itoa_base(MAX_LONG_LONG + n, 8));
	else if (c == 'O' && n >= 0)
		ret = pr_putstr(pr_itoa_base(n, 8));
	else if (c == 'D' && n < 0)
		ret = pr_putstr(pr_itoa_base(MAX_LONG + n, 10));
	else if (c == 'D' && n >= 0)
		ret = pr_putstr(pr_itoa_base(n, 10));
	return (ret);
}

int		pr_format(char *s, va_list ap)
{
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (!(pr_strchr(FMT, *(s + i))) && *(s + i))
		i++;
	if (*(s + i) == '%' || *(s + i) == 'c' || *(s + i) == 's')
		ret = pr_chars(ap, *(s + i));
	else if (*(s + i) == 'i' || *(s + i) == 'd' || *(s + i) == 'u')
		ret = pr_ints(ap, *(s + i));
	else if (*(s + i) == 'o' || *(s + i) == 'x' || *(s + i) == 'X')
		ret = pr_bases(ap, *(s + i));
	else if (*(s + i) == 'O' || *(s + i) == 'U' || *(s + i) == 'D')
		ret = pr_longints(ap, *(s + i));
	else if (*(s + i) == 'p')
		ret = pr_putaddr(ap);
	return (ret);
}
