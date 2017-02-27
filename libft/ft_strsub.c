/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:40:36 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 17:04:31 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((int)len < 0)
		return (NULL);
	i = 0;
	s2 = (char*)malloc(sizeof(*s2) * len + 1);
	if (!s2)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}
