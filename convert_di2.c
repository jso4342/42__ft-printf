/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:54:54 by sjang             #+#    #+#             */
/*   Updated: 2020/02/27 17:35:50 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_neg(int n, t_format *c, unsigned int *nbr)
{
	if (n != INT_MIN || c->dot == 0)
	{
		if (n == INT_MIN)
			(c->zero == 1) ? NULL : ft_putchar('-', c);
		else
			ft_putchar('-', c);
	}
	else
	{
		if (n == INT_MIN && c->prer >= 11)
			(c->neg == 1 && c->prec == 11) ? ft_putchar('-', c) : NULL;
		else
			ft_putchar('-', c);
	}
	if (c->extra == 1)
	{
		ft_putchar('0', c);
		c->extra2 = 1;
	}
	*nbr = (unsigned int)(n * -1);
}

void	ft_putnbr(int n, t_format *c)
{
	unsigned int	nbr;

	if (n < 0)
		ft_check_neg(n, c, &nbr);
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, c);
	ft_putchar((nbr % 10) + 48, c);
}

void	ft_pre_d_neg1(t_format *c, int n, int size, int j)
{
	int				p;

	p = c->prec;
	if (c->pre == 0 && c->zero == 1 && c->neg == 0)
		return ;
	else if ((c->pre == 1 && p == 0 && n == 0) ||
			(c->pre == 0 && c->mwf == 1 && n == 0))
		ft_putchar(' ', c);
	else
	{
		if (c->prec == size)
			c->extra = 1;
		ft_putnbr(n, c);
		if (c->extra2 == 1)
			j--;
	}
	while (j-- > 0)
		ft_putchar(' ', c);
}

void	ft_pre_d_rest(t_format *c, int n, int size, int j)
{
	if (size < c->prec)
	{
		c->prec = c->prec - size;
		if (n < 0)
		{
			ft_putchar('-', c);
			c->prec = c->prec + 1;
			n = n * (-1);
		}
		while (c->prec-- > 0)
			ft_putchar('0', c);
	}
	ft_pre_d_neg1(c, n, size, j);
}

void	ft_pre_condition(t_format *c, int n)
{
	int				p;

	p = c->prec;
	if ((c->pre == 0 && c->width == 0 && n == 0 && c->starstar == 0)
			|| (c->pre == 1 && !p && c->width == 0 & n == 0))
		return ;
	if ((c->pre == 0 && c->width == 0 && n == 0) || (c->pre == 1
				&& !p && c->width == 0 & n == 0 && c->starstar == 1))
		ft_putchar('0', c);
	else if ((c->pre == 1 && p == 0 && n == 0) ||
			(c->pre == 0 && c->mwf == 1 && n == 0))
		ft_putchar(' ', c);
	else
		ft_putnbr(n, c);
}
