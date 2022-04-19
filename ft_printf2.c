/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:45:38 by sjang             #+#    #+#             */
/*   Updated: 2020/02/22 22:04:38 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*save(const char *format, int start, int end, t_format *c)
{
	int			i;
	char		*storage;

	start++;
	c->formatlen++;
	i = 0;
	if (!(storage = malloc(sizeof(end - start + 1))))
		return (NULL);
	while ((start != end))
	{
		storage[i] = format[start];
		i++;
		start++;
		c->formatlen++;
	}
	storage[i] = '\0';
	c->flags = ft_strdup(storage);
	free(storage);
	return (c->flags);
}

int		ft_get_width(t_format *c, char *extract, int *i)
{
	int			j;
	int			start;
	char		*storage;

	start = *i;
	while (ft_isdigit(extract[start]))
		start++;
	if (!(storage = (char *)malloc(sizeof(start - *i))))
		return (-1);
	j = 0;
	while (*i < start)
	{
		storage[j] = extract[*i];
		j++;
		*i = *i + 1;
	}
	*i = *i - 1;
	storage[j] = '\0';
	c->width = ft_atoi(storage);
	free(storage);
	return (0);
}

int		ft_get_precision(t_format *c, char *extract, int *i)
{
	int			j;
	int			start;
	char		*storage;

	*i = *i + 1;
	c->pre = 1;
	start = *i;
	while (ft_isdigit(extract[start]))
		start++;
	if (!(storage = (char *)malloc(sizeof(start - *i))))
		return (-1);
	j = 0;
	while (*i < start)
	{
		storage[j] = extract[*i];
		j++;
		*i = *i + 1;
	}
	storage[j] = '\0';
	c->prec = ft_atoi(storage);
	free(storage);
	return (0);
}

int		check_format2(char *extract, t_format *c, int *i)
{
	if (extract[*i] == '*')
	{
		if (c->star == 1)
			c->starstar = 1;
		c->star = 1;
		if (extract[*i - 1] == '.')
			c->starpre = 1;
	}
	if (!extract[*i])
		i++;
	if ((extract[*i] >= '1') && (extract[*i] <= '9'))
	{
		if (c->mwf != 1)
		{
			if (ft_get_width(c, extract, &*i) == -1)
				return (-1);
		}
		c->mwf = 1;
	}
	return (0);
}

int		check_format(char *extract, t_format *c)
{
	int			i;

	i = 0;
	while (extract[i])
	{
		if (extract[i] == '-')
			c->neg = 1;
		if (extract[i] == '0')
			c->zero = 1;
		if (extract[i] == '.')
		{
			c->dot = 1;
			if ((extract[i + 1] >= '0') && (extract[i + 1] <= '9'))
			{
				if (ft_get_precision(c, extract, &i) == -1)
					return (-1);
			}
		}
		else if (check_format2(extract, c, &i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
