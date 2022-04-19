/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:49:33 by sjang             #+#    #+#             */
/*   Updated: 2020/02/17 19:31:39 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char					*p;
	int						i;
	int						len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	if (!(p = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free((void *)s1);
		s1 = NULL;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
