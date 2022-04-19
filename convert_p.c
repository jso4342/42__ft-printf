/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:03:51 by sjang             #+#    #+#             */
/*   Updated: 2020/02/25 18:56:58 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_j(t_format *c, int size)
{
	int j;

	j = 0;
	if (c->width > c->prec && c->prec > size)
		j = c->width - c->prec;
	if (c->width > c->prec && c->prec <= size)
		j = c->width - size;
	if (c->width > 11)
		j = j - 2;
	return (j);
}

void	ft_pre_p(t_format *c, unsigned long long n, int size)
{
	int				j;

	j = ft_get_j(c, size);
	if (c->dot == 1 && c->mwf != 0 && n == (unsigned long long)NULL)
		ft_null(c, n, size);
	else if (c->neg == 0)
	{
		while (j-- > 0)
			ft_putchar(' ', c);
		if (size < c->prec)
		{
			ft_putstr("0x", c);
			while (c->prec-- > size)
				ft_putchar('0', c);
			add(n, 16, c);
			return ;
			c->prec = c->prec - size;
			while (c->prec-- > 0)
				ft_putchar('0', c);
		}
		ft_pre_rest(c, n);
	}
	else
		ft_else(c, n, j, size);
}

void	ft_dot_p(t_format *c, unsigned long long n, int size, int i)
{
	if (c->width > size)
	{
		ft_putstr("0x", c);
		i = i - 2;
	}
	while (i-- > 0)
		ft_putchar('0', c);
	if (n == 0)
		ft_putchar('0', c);
	if ((void *)n == NULL)
		ft_putstr("000", c);
	else
		add(n, 16, c);
}

void	ft_mwf_p(t_format *c, unsigned long long n, int size)
{
	int					i;

	i = c->width;
	i = i - size;
	if (c->neg == 1)
	{
		if (c->dot == 1)
			ft_pre_p(c, n, size);
		else
		{
			add(n, 16, c);
			while (i-- > 0)
				ft_putchar(' ', c);
		}
	}
	else if (c->zero == 1 && c->dot == 0)
		(n <= 0) ? ft_dot_p(c, n, size, i - 1) : ft_dot_p(c, n, size, i);
	else if (c->dot == 1)
		ft_pre_p(c, n, size);
	else
	{
		while (i-- > 0)
			ft_putchar(' ', c);
		add(n, 16, c);
	}
}

void	convert_p(va_list ap, t_format *c)
{
	unsigned long		p;
	int					k;
	int					i;

	if (c->star == 1)
	{
		k = va_arg(ap, int);
		ft_manage_star(c, k, ap);
	}
	p = va_arg(ap, unsigned long);
	i = ft_howmany_placevalue_p(p, 16) + 2;
	if (c->mwf == 1)
		ft_mwf_p(c, p, i);
	else if (c->dot == 1)
		ft_pre_p(c, p, i);
	else
		add(p, 16, c);
}
