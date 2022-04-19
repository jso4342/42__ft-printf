/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:54:54 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 20:03:05 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_base_itoa(unsigned int d, int n, t_format *c)
{
	unsigned int div;
	unsigned int num;
	unsigned int base;

	div = 1;
	base = (unsigned int)n;
	while (d / div >= base)
		div *= base;
	while (div != 0)
	{
		num = d / div;
		d = d % div;
		div /= base;
		if (num > 9)
		{
			if (c->capital == 1)
				ft_putchar((num - 10) + 'a' - 32, c);
			else
				ft_putchar((num - 10) + 'a', c);
		}
		else
			ft_putchar(num + '0', c);
	}
}

void	ft_pre_neg(t_format *c, unsigned int n, int k, int j)
{
	int				p;
	int				size;

	size = ft_howmany_placevalue(n, k);
	p = c->prec;
	while (j-- > 0)
		ft_putchar(' ', c);
	if (size < c->prec)
	{
		c->prec = c->prec - size;
		while (c->prec-- > 0)
			ft_putchar('0', c);
	}
	if ((c->pre == 0 && c->width == 0 && n == 0) ||
			(c->pre == 1 && !p && c->width == 0 & n == 0))
		return ;
	else if ((c->pre == 1 && p == 0 && n == 0) ||
			(c->pre == 0 && c->mwf == 1 && n == 0))
		ft_putchar(' ', c);
	else
		ft_base_itoa(n, k, c);
}
