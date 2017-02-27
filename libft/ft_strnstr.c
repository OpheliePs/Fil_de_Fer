/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:49:25 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/07 11:55:03 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j < n))
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
