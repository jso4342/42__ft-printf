/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:27:57 by sjang             #+#    #+#             */
/*   Updated: 2019/10/16 18:20:34 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	source = (char *)src;
	dest = dst;
	i = 0;
	if (len == 0 || dst == src)
		return (dst);
	if (source < dest)
	{
		while (++i <= len)
			dest[len - i] = source[len - i];
	}
	else
	{
		while (len-- > 0)
			*(dest++) = *(source++);
	}
	return (dst);
}
