/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:12:07 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/09 15:35:57 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				pr_measure(long dup, int base, int l)
{
	while (dup > 0)
	{
		dup /= base;
		l++;
	}
	return (l);
}

char			*pr_itoa_base(long n, int base)
{
	char		*tab;
	char		*s;
	long long	dup;
	int			l;

	if (n == 0)
		return("0");
	tab = (char *)malloc(17 * sizeof(char));
	pr_bzero(tab, 17);
	tab = "0123456789ABCDEF";
	l = 0;
	dup = n;
	l = (base == 10 && dup < 0) ? 1 : 0;
	dup = (dup < 0) ? -dup : dup;
	l = pr_measure(dup, base, l);
	if(!(s = (char *)malloc((l) * sizeof(char))))
		return("0");
	pr_bzero(s, l);
	dup = n;
	dup = (dup < 0) ? -dup : dup;
	while (l-- >= 0)
	{
		*(s + l) = *(tab + (dup % base));
		dup /= base;
	}
	s[0] = (n < 0 && base == 10) ? '-' : s[0];
	return (s);
}
