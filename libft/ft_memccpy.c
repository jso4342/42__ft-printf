/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:17:37 by sjang             #+#    #+#             */
/*   Updated: 2019/10/16 18:18:25 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)d;
	source = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if (dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		++i;
	}
	return (0);
}
