/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:23:49 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 17:24:10 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pre_s(t_format *c, char *s)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	if (i > c->prec)
	{
		while (c->prec-- > 0)
		{
			ft_putchar(s[j], c);
			j++;
		}
	}
	else
		ft_putstr(s, c);
}

void	ft_mwf_s_ng(t_format *c, char *s, int i)
{
	if (c->pre == 1)
	{
		if (c->prec > ft_strlen(s))
			i = c->width - ft_strlen(s);
		else
			i = c->width - c->prec;
		ft_pre_s(c, s);
	}
	else
		(c->dot == 1) ? (i = i + ft_strlen(s)) : ft_putstr(s, c);
	while (i-- > 0)
		ft_putchar(' ', c);
}

void	ft_mwf_s_pre(t_format *c, char *s, int i)
{
	if (c->pre == 1)
	{
		if (c->prec > ft_strlen(s))
			i = c->width - ft_strlen(s);
		else
			i = c->width - c->prec;
	}
	if (c->dot == 1 && c->pre == 0 && c->zero == 1)
	{
		i = c->width;
		while (i--)
			ft_putchar(' ', c);
		return ;
	}
	while (i-- > 0)
		((c->width > ft_strlen(s) || c->dot == 1) && c->zero == 1) ?
			ft_putchar('0', c) : ft_putchar(' ', c);
}

void	ft_mwf_s(t_format *c, char *s)
{
	int		i;

	i = c->width;
	i = i - ft_strlen(s);
	if (c->neg == 1)
		ft_mwf_s_ng(c, s, i);
	else
	{
		ft_mwf_s_pre(c, s, i);
		if (c->pre == 1)
			(c->prec == 0) ? NULL : ft_pre_s(c, s);
		else
		{
			if (c->dot == 1 && c->zero == 0)
			{
				i = ft_strlen(s);
				if (i > c->width)
					i = c->width;
				while (i--)
					ft_putchar(' ', c);
			}
			else
				ft_putstr(s, c);
		}
	}
}

void	convert_s(va_list ap, t_format *c)
{
	char	*s;
	int		d;

	d = 0;
	if (c->star == 1)
	{
		d = va_arg(ap, int);
		ft_manage_star(c, d, ap);
	}
	s = va_arg(ap, char *);
	if (!s)
	{
		if (c->mwf == 1 && c->dot == 1 && c->pre == 0)
			s = "";
		else
			s = "(null)";
	}
	if (c->mwf == 1)
		ft_mwf_s(c, s);
	else if (c->pre == 1)
		ft_pre_s(c, s);
	else
		c->dot == 1 ? NULL : ft_putstr(s, c);
}
