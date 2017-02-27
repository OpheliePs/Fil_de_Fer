/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:33:19 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/29 12:15:12 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*add;

	add = (char*)malloc(sizeof(*add) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (add == NULL)
		return (NULL);
	ft_strcpy(add, s1);
	ft_strcat(add, s2);
	return (add);
}
