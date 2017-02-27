/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:06:43 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 17:49:50 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*dst2;
	unsigned char	*src2;

	i = 0;
	c2 = (unsigned char)c;
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	while (i < n && src2[i] != c2)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (i == n)
		return (NULL);
	if (src2[i] == c2)
	{
		dst2[i] = src2[i];
		i++;
	}
	return ((void*)dst + i);
}
