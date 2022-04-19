/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 21:33:35 by sjang             #+#    #+#             */
/*   Updated: 2019/10/20 19:05:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int		ft_size(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		ft_myfree(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || !(p = (char**)malloc(sizeof(char*) * (count(s, c) + 1))))
		return (NULL);
	while (count(s, c) > ++i)
	{
		k = 0;
		if (!(p[i] = (char*)malloc(sizeof(char) * (ft_size(&s[j], c) + 1))))
		{
			ft_myfree(p);
			return (NULL);
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			p[i][k++] = s[j++];
		p[i][k] = '\0';
	}
	p[i] = 0;
	return (p);
}
