/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:54:54 by sjang             #+#    #+#             */
/*   Updated: 2020/02/25 18:48:09 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_j_di(t_format *c, int n, int size)
{
	int				j;

	j = 0;
	if (c->width > c->prec && c->prec > size)
	{
		j = c->width - c->prec;
		if (n < 0)
			j = j - 1;
	}
	if (c->width > c->prec && c->prec <= size)
		j = c->width - size;
	return (j);
}

void	ft_pre_d(t_format *c, int n, int size)
{
	int				j;

	j = ft_get_j_di(c, n, size);
	if (c->neg == 0)
	{
		if (size == c->prec && n < 0)
			j = j - 1;
		while (j-- > 0)
			ft_putchar(' ', c);
		if ((size < c->prec) || (size == c->prec && n < 0))
		{
			c->prec = c->prec - size;
			if (n < 0)
			{
				c->prec = c->prec + 1;
				ft_putchar('-', c);
				n = n * (-1);
			}
			while (c->prec-- > 0)
				ft_putchar('0', c);
		}
		ft_pre_condition(c, n);
	}
	else
		ft_pre_d_rest(c, n, size, j);
}

void	ft_dot_di(t_format *c, int n, int i)
{
	if (n < 0)
	{
		ft_putchar('-', c);
		n = n * -1;
		i++;
	}
	while (i-- > 0)
	{
		if (c->width > c->prec && c->dot == 1)
			ft_putchar(' ', c);
		else
			ft_putchar('0', c);
	}
	if (n == 0 && c->width != 1)
		ft_putchar('0', c);
	ft_putnbr(n, c);
}

void	ft_mwf_di(t_format *c, int n, int size)
{
	int		i;

	i = c->width;
	i = i - size;
	if (c->neg == 1)
	{
		if (c->dot == 1)
			ft_pre_d(c, n, size);
		else
		{
			ft_putnbr(n, c);
			while (i-- > 0)
				ft_putchar(' ', c);
		}
	}
	else if (c->zero == 1 && c->dot == 0)
		(n <= 0) ? ft_dot_di(c, n, i - 1) : ft_dot_di(c, n, i);
	else if (c->dot == 1)
		ft_pre_d(c, n, size);
	else
	{
		while (i-- > 0)
			ft_putchar(' ', c);
		ft_putnbr(n, c);
	}
}

void	convert_di(va_list ap, t_format *c)
{
	int		d;
	int		i;

	d = 0;
	i = 0;
	if (c->star == 1)
	{
		i = va_arg(ap, int);
		ft_manage_star(c, i, ap);
	}
	d = va_arg(ap, int);
	i = ft_howmany_placevalue_d(d, 10);
	c->prer = c->prec;
	if (c->mwf == 1)
		ft_mwf_di(c, d, i);
	else if (c->dot == 1)
		ft_pre_d(c, d, i);
	else
		ft_putnbr(d, c);
}
