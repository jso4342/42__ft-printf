/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 20:28:54 by sjang             #+#    #+#             */
/*   Updated: 2020/02/11 21:18:15 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mwf_percent(t_format *c, char a)
{
	int		i;

	i = c->width;
	if (c->neg == 1)
	{
		ft_putchar(a, c);
		while (i-- > 1)
			ft_putchar(' ', c);
	}
	else
	{
		while (i-- > 1)
		{
			if (c->zero == 1)
				ft_putchar('0', c);
			else
				ft_putchar(' ', c);
		}
		ft_putchar(a, c);
	}
}

void	convert_percent(va_list ap, t_format *c)
{
	char	a;
	int		i;

	a = '%';
	if (c->star == 1)
	{
		i = va_arg(ap, int);
		ft_manage_star(c, i, ap);
	}
	if (c->mwf == 1)
		ft_mwf_percent(c, a);
	else
		ft_putchar(a, c);
}
