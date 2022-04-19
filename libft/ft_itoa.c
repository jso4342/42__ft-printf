/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 22:38:54 by sjang             #+#    #+#             */
/*   Updated: 2019/10/18 20:13:48 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_size(int nbr)
{
	int i;

	i = 0;
	if (nbr <= 0)
		i = 1;
	else
		i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	int				sign;
	int				size;
	char			*p;

	sign = (n < 0) ? 1 : 0;
	nbr = (n < 0) ? -n : n;
	size = check_size(n);
	if (!(p = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	p[size--] = '\0';
	while (size >= 0)
	{
		p[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	if (sign == 1)
		p[0] = '-';
	return (p);
}
