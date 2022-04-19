/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:37:37 by sjang             #+#    #+#             */
/*   Updated: 2019/10/16 18:29:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	if (n == 0)
		return (0);
	ptr = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (*ptr == *ptr2 && ++i < (int)n)
	{
		ptr++;
		ptr2++;
	}
	return ((int)(*ptr - *ptr2));
}
