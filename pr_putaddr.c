/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 10:15:33 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/13 10:25:07 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LOWERCASE 1

int		pr_putaddr(va_list ap)
{
	long	p;
	int		ret;

	ret = 0;
	p = (long)(va_arg(ap, void *));
	ret = pr_putstr("0x");
	ret += pr_putstr_case(pr_itoa_base(p, 16), LOWERCASE);
	return (ret);
}
