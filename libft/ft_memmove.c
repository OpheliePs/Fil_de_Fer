/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:56:01 by opettex-          #+#    #+#             */
/*   Updated: 2016/01/18 16:39:08 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = len;
	if (dst > src)
	{
		while (i > 0)
		{
			((unsigned char*)dst)[i - 1] = ((unsigned char*)src)[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
