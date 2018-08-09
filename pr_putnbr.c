/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 10:56:56 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/09 15:55:02 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pr_putnbr(int n)
{
	long	number;
	int		ret;

	ret = 0;
	number = (long)n;
	if (number < 0)
	{
		ret += pr_putchar('-');
		number = number * -1;
	}
	if (number >= 10)
	{
		pr_putnbr(number / 10);
		pr_putnbr(number % 10);
	}
	else
	{
		ret += pr_putchar(number + '0');
	}
	return(ret);
}
