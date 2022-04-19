/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:07:02 by sjang             #+#    #+#             */
/*   Updated: 2019/10/16 18:21:36 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char *p;

	i = 0;
	p = (const unsigned char*)s;
	while (++i <= n)
	{
		if (*(p++) == (const unsigned char)c)
			return ((void*)--p);
	}
	return (0);
}
