/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:23:35 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 15:17:24 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		end;
	int		t;

	i = 0;
	t = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			tab[t++] = ft_strsub(s, start, (end - start));
	}
	tab[t] = NULL;
	return (tab);
}
