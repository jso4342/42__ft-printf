/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:16:55 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 21:31:07 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char s, t_format *c)
{
	write(1, &s, 1);
	c->len++;
}

void		ft_putstr(char *s, t_format *c)
{
	int						i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], c);
		i++;
	}
}

void		ft_strdel(char *s)
{
	if (s)
		free(s);
}

void		ft_set_struct(t_format *c)
{
	c->neg = 0;
	c->mwf = 0;
	c->zero = 0;
	c->formatlen = 0;
	c->dot = 0;
	c->star = 0;
	c->capital = 0;
	c->width = 0;
	c->prec = 0;
	c->pre = 0;
	c->prer = 0;
	c->starpre = 0;
	c->starstar = 0;
	c->extra = 0;
	c->extra2 = 0;
}

int			size_flags(const char *s, t_format *c, int start)
{
	int i;

	c->formatlen++;
	i = start + 1;
	while (s[i])
	{
		if (s[i] == 's' || s[i] == 'd' || s[i] == 'i' || s[i] == 'u'
				|| s[i] == '%' || s[i] == 'c' || s[i] == 'p' ||
				s[i] == 'x' || s[i] == 'X')
			break ;
		else
		{
			i++;
			c->formatlen++;
		}
	}
	return (i);
}
