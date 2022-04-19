/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:44:49 by sjang             #+#    #+#             */
/*   Updated: 2019/10/21 18:09:08 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		j;
	char	*tab;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	j = ft_strlen(s1);
	while (*s1 != '\0' && ft_check(*(s1 + (j - 1)), set) == 1 && j)
		j--;
	while (*s1 != '\0' && ft_check(*s1, set) == 1 && j)
	{
		j--;
		s1++;
	}
	if (!(tab = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	p = tab;
	while (j--)
		*tab++ = *s1++;
	*tab = 0;
	return (p);
}
