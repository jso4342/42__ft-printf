/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:52:14 by sjang             #+#    #+#             */
/*   Updated: 2020/02/11 20:16:21 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mwf_c(t_format *c, char a)
{
	if (c->neg == 1)
	{
		ft_putchar(a, c);
		while (c->width - 1 != 0 && c->width != 0)
		{
			ft_putchar(' ', c);
			c->width--;
		}
	}
	else
	{
		while (c->width - 1 != 0 && c->width != 0)
		{
			if (c->zero == 1)
				ft_putchar('0', c);
			else
				ft_putchar(' ', c);
			c->width--;
		}
		ft_putchar(a, c);
	}
}

void	convert_c(va_list ap, t_format *c)
{
	char	a;
	int		i;

	if (c->star == 1)
	{
		i = va_arg(ap, int);
		ft_manage_star(c, i, ap);
	}
	a = va_arg(ap, int);
	if (c->mwf == 1)
		ft_mwf_c(c, a);
	else
	{
		ft_putchar(a, c);
	}
}
