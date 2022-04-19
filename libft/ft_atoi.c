/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:12:25 by sjang             #+#    #+#             */
/*   Updated: 2019/10/18 20:08:07 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == ' '
			|| c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int								neg;
	unsigned long long				nbr;

	neg = 1;
	nbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + *str - '0';
		if (nbr > 9223372036854775807)
			return ((neg + 1) / -2);
		str++;
	}
	return ((int)nbr * neg);
}
