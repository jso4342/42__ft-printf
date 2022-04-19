/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:03:51 by sjang             #+#    #+#             */
/*   Updated: 2020/02/25 18:47:34 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add(unsigned long long d, unsigned long long base, t_format *c)
{
	unsigned long long	div;
	unsigned long long	num;
	int					i;

	div = 1;
	i = ft_howmany_placevalue_p(d, 16) + 2;
	while (d / div >= base)
		div *= base;
	if (c->dot == 1 && c->neg == 0 && c->mwf == 1 && c->zero == 1)
		return ;
	else
		(((c->dot == 1 && c->mwf == 1 && i <= c->prec) || (c->zero == 1
		&& c->neg == 0 && c->dot == 0 && c->mwf == 1 && c->width > i) ||
		(c->zero == 0 && c->neg == 0 && c->dot == 1 && c->mwf == 0 &&
		i <= c->prec))) ? ft_putstr("00", c) : ft_putstr("0x", c);
	while (div != 0)
	{
		num = d / div;
		d = d % div;
		div /= base;
		if (num > 9)
			ft_putchar((num - 10) + 'a', c);
		else
			ft_putchar(num + '0', c);
	}
}

void	ft_else(t_format *c, unsigned long long n, int j, int size)
{
	int				p;

	p = c->prec;
	if (size < c->prec)
	{
		c->prec = c->prec - size;
		while (c->prec-- > 0)
			ft_putchar('0', c);
	}
	if (c->pre == 0 && c->zero == 1)
		return ;
	if (n == (unsigned long long)NULL)
	{
		ft_putstr("0x", c);
		j = j + 1;
	}
	else if ((c->pre == 1 && p == 0 && n == 0) ||
			(c->pre == 0 && c->mwf == 1 && n == 0))
		ft_putchar(' ', c);
	else
		add(p, 16, c);
	while (j-- > 0)
		ft_putchar(' ', c);
}

void	ft_pre_rest(t_format *c, unsigned long long n)
{
	int				p;

	p = c->prec;
	if ((c->pre == 0 && c->width == 0 && n == 0) ||
			(c->pre == 1 && !p && c->width == 0 & n == 0))
		ft_putstr("0x", c);
	else if ((c->pre == 1 && p == 0 && n == 0) ||
			(c->pre == 0 && c->mwf == 1 && n == 0))
		ft_putchar(' ', c);
	else
		add(n, 16, c);
}

void	ft_null(t_format *c, unsigned long long n, int size)
{
	int				j;

	j = c->width - 2;
	if (c->neg == 0)
	{
		if (c->width <= 2)
			ft_putstr("0x", c);
		else
		{
			while (j-- > 0)
				ft_putchar(' ', c);
			ft_putstr("0x", c);
		}
	}
	else
	{
		ft_putstr("0x", c);
		while (j-- > 0)
			ft_putchar(' ', c);
	}
}
