/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:27:19 by sjang             #+#    #+#             */
/*   Updated: 2019/10/16 18:30:18 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = (0);
	while (*s)
	{
		if (*s == c)
			a = (char*)s;
		++s;
	}
	if (a)
		return (a);
	if (c == '\0')
		return ((char*)s);
	return (0);
}