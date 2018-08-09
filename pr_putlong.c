/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 12:08:03 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/06 17:12:14 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pr_putlong(long n)
{
	long long	number;
	int			ret;

	ret = 0;
	number = (long long)n;
	if (number < 0)
	{
		pr_putchar('-');
		number = number * -1;
	}
	if (number >= 10)
	{
		pr_putlong(number / 10);
		pr_putlong(number % 10);
	}
	else
	{
		pr_putchar(number + '0');
		ret++;
	}
	return(1);
}
