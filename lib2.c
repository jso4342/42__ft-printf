/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:16:55 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 20:05:51 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_howmany_placevalue(unsigned int a, unsigned int base)
{
	unsigned int			i;
	int						check;

	i = a;
	check = 0;
	if (a == 0)
		return (1);
	if (i <= 0)
	{
		i = i * (-1);
		check++;
	}
	while ((i / base) != 0)
	{
		i = i / base;
		check++;
	}
	return (check + 1);
}

int			ft_howmany_placevalue_d(int a, int base)
{
	int						i;
	int						check;

	i = a;
	check = 0;
	if (a == 0)
		return (1);
	if (i <= 0)
	{
		i = i * (-1);
		check++;
	}
	while ((i / base) != 0)
	{
		i = i / base;
		check++;
	}
	return (check + 1);
}

int			ft_howmany_placevalue_p(unsigned long a, unsigned long base)
{
	unsigned long			i;
	int						check;

	i = a;
	check = 0;
	if (a == 0)
		return (1);
	if (i <= 0)
	{
		i = i * (-1);
		check++;
	}
	while ((i / base) != 0)
	{
		i = i / base;
		check++;
	}
	return (check + 1);
}

void		ft_substar(t_format *c, int n)
{
	if (c->starpre == 1)
	{
		if (n < 0)
			c->dot = 0;
		else
		{
			c->prec = n;
			c->pre = 1;
		}
	}
	else
	{
		if (n < 0)
		{
			c->neg = 1;
			n = n * (-1);
		}
		if (c->mwf == 1)
			return ;
		c->width = n;
		c->mwf = 1;
	}
}

void		ft_manage_star(t_format *c, int n, va_list ap)
{
	int						d;

	d = 0;
	if (c->starstar == 1)
	{
		if (n < 0)
		{
			c->neg = 1;
			n = n * (-1);
		}
		c->width = n;
		c->mwf = 1;
		d = va_arg(ap, int);
		if (d < 0)
			c->dot = 0;
		else
		{
			c->pre = 1;
			c->prec = d;
		}
	}
	else
		ft_substar(c, n);
}
