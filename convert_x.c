/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:54:54 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 17:57:16 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pre_x(t_format *c, unsigned int n, int size)
{
	int				i;
	int				j;
	int				p;

	p = c->prec;
	i = 0;
	j = 0;
	if (c->width > c->prec && c->prec > size)
		j = c->width - c->prec;
	if (c->width > c->prec && c->prec <= size)
		j = c->width - size;
	if (c->neg == 0)
		ft_pre_neg(c, n, 16, j);
	else
		ft_pre_else(c, n, 16, j);
}

void	ft_dot_x(t_format *c, int n, int i)
{
	while (i-- > 0)
		ft_putchar('0', c);
	if (n == 0 && c->width != 1)
		ft_putchar('0', c);
	ft_base_itoa(n, 16, c);
}

void	ft_mwf_x(t_format *c, unsigned int n, int size)
{
	int		i;

	i = c->width;
	i = i - size;
	if (c->neg == 1)
	{
		if (c->dot == 1)
			ft_pre_x(c, n, size);
		else
		{
			ft_base_itoa(n, 16, c);
			while (i-- > 0)
				ft_putchar(' ', c);
		}
	}
	else if (c->zero == 1 && c->dot == 0)
		(n <= 0) ? ft_dot_x(c, n, i - 1) : ft_dot_x(c, n, i);
	else if (c->dot == 1)
		ft_pre_x(c, n, size);
	else
	{
		while (i-- > 0)
			ft_putchar(' ', c);
		ft_base_itoa(n, 16, c);
	}
}

void	convert_x(va_list ap, t_format *c)
{
	unsigned int		u;
	int					i;
	int					k;

	if (c->star == 1)
	{
		k = va_arg(ap, int);
		ft_manage_star(c, k, ap);
	}
	u = va_arg(ap, unsigned int);
	i = ft_howmany_placevalue(u, 16);
	if (c->mwf == 1)
		ft_mwf_x(c, u, i);
	else if (c->dot == 1)
		ft_pre_x(c, u, i);
	else
		ft_base_itoa(u, 16, c);
}
