/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:38:04 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/10 15:21:55 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	wchar_t			*wchr;
	int				i;
	int				d;
	char			c;
	char			s[] = "SENTENCE";
	unsigned int	u;
	unsigned int	o;
	unsigned int	x;
	int				*p;

	i = -1000;
	d = -1;
	c = 'a';
	u = -1;
	o = -1; //check if negated is expressed in octal
	x = -1;
	p = &i;
	
	ft_printf(" %% %c %s %i %D %U %O %x %p \n", c, s, i, d, u, -1, -202, p);
	   printf(" %% %c %s %i %D %U %O %x %p \n", c, s, i, d, u, -1, -202, p);
	ft_printf("   %i \n", ft_printf("%u", -1));
	   printf("   %i \n",    printf("%u", -1));

	return(0);
}

