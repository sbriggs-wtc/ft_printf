/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:06:30 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/15 17:27:24 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pr_putwstr(va_list ap, char c)
{
	wchar_t	*ws;
	int		ret;
	int		i;

	if (c == 'C')
		return (pr_putwchar(ap));
	ret = 0;
	i = 0;
	ws = va_arg(ap, wchar_t *);
	while (*(ws + i))
	{
		ret += pr_putchar(*(ws + i));
		i++;
	}
	return (ret);
}
