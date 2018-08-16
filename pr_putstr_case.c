/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putstr_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:42:03 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/10 15:13:21 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int			pr_putstr_case(char *s, int c)
{
	int		i;
	char	zero;

	zero = '0';
	if (s[0] == 0 && s[1] == '\0')
	{
		write(1, &zero, 1);
		return (1);
	}
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (c == 0)
			write(1, &s[i], 1);
		else if (c == 1)
			pr_putchar(pr_tolower(*(s + i)));
		else if (c == 2)
			pr_putchar(pr_toupper(*(s + i)));
		i++;
	}
	return (i);
}
