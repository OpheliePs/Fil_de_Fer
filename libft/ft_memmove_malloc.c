/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:31:32 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/29 13:16:24 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove_malloc(void *dst, const void *src, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ((char*)malloc(sizeof(*tmp) * len));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dst);
}
