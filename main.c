/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:38:04 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/09 16:12:02 by sbriggs          ###   ########.fr       */
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
	char			s[] = "THIS IS A SENTENCE";
	unsigned int	u;
	unsigned int	o;
	unsigned int	x;
	int				*p;

	i = -1000;
	d = -1000;
	c = 'a';
	u = -1;
	o = -1; //check if negated is expressed in octal
	x = -1;
	p = &i;
	
	ft_printf(" %% %c %s %i %d %u %o %X %p \n", c, s, i, d, u, o, 0, p);
	   printf(" %% %c %s %i %d %u %o %X %p \n", c, s, i, d, u, o, 0, p);
	   printf("   %i \n", ft_printf("%u", -1));
	   printf("   %i \n",    printf("%u", -1));

	return(0);
}

