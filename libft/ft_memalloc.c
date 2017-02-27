/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:37:08 by opettex-          #+#    #+#             */
/*   Updated: 2015/11/28 13:47:58 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*zm;

	i = 0;
	zm = (char*)malloc(sizeof(*zm) * size);
	if (zm == NULL)
		return (NULL);
	while (i < size)
	{
		((char*)zm)[i] = 0;
		i++;
	}
	((char*)zm)[i] = '\0';
	return (zm);
}
