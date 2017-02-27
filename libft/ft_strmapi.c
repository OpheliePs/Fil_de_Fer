/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:28:37 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 15:29:54 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (!s)
		return (NULL);
	s2 = ft_strnew(ft_strlen(s));
	if (!s2)
		return (NULL);
	if (s && f)
	{
		while (s[i] != '\0')
		{
			s2[i] = f(i, s[i]);
			i++;
		}
	}
	return (s2);
}
