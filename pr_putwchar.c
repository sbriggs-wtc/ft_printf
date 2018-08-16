/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:36:05 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/16 10:18:06 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pr_putwchar(va_list ap)
{
	wchar_t	wc;
	int		i;

	i = 0;
	wc = va_arg(ap, wchar_t);
	pr_putchar(wc);
	return (1);
}
