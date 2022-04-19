/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:45:38 by sjang             #+#    #+#             */
/*   Updated: 2020/02/20 16:50:16 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check2(const char *s, int i, va_list ap, t_format *c)
{
	if (s[i] == 's')
		convert_s(ap, c);
	else if (s[i] == 'd' || s[i] == 'i')
		convert_di(ap, c);
	else if (s[i] == 'u')
		convert_u(ap, c);
	else if (s[i] == 'p')
		convert_p(ap, c);
	else if (s[i] == 'x' || s[i] == 'X')
	{
		if (s[i] == 'X')
			c->capital = 1;
		convert_x(ap, c);
	}
	else if (s[i] == '%')
		convert_percent(ap, c);
	else
		return (-1);
	return (0);
}

static int		checkcon(const char *s, int i, va_list ap, t_format *c)
{
	if (s[i] == 'c')
		convert_c(ap, c);
	else
	{
		if (check2(s, i, ap, c) == -1)
			return (-1);
	}
	return (0);
}

static int		ft_print(const char *format, va_list ap, t_format *c, int *i)
{
	int			start;
	int			end;
	int			check;
	char		*storage;

	check = 1;
	start = *i;
	ft_set_struct(c);
	end = size_flags(format, c, *i);
	if ((storage = save(format, *i, end, c)) == NULL)
	{
		free(storage);
		return (-1);
	}
	*i = end;
	if (check_format(storage, c) == -1)
	{
		free(storage);
		return (-1);
	}
	free(storage);
	if (checkcon(format, end, ap, c) == -1)
		return (-1);
	return (0);
}

static int		formatcheck(const char *format, va_list ap, t_format *c, int *i)
{
	if (format[*i] == '%')
	{
		if (ft_print(format, ap, c, &*i) == -1)
			return (-1);
	}
	else
	{
		ft_putchar(format[*i], c);
		c->formatlen++;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	t_format	c;

	va_start(ap, format);
	i = 0;
	c.len = 0;
	while (format[i] != '\0')
	{
		if (formatcheck(format, ap, &c, &i) == -1)
			return (-1);
		i++;
	}
	va_end(ap);
	i = c.len;
	return (i);
}
