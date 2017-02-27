/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:00:44 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 17:06:36 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

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
			s2[i] = f(s[i]);
			i++;
		}
	}
	return (s2);
}
