/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:28:11 by opettex-          #+#    #+#             */
/*   Updated: 2016/01/18 16:48:38 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrevchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_bzero(str, ft_strlen(s));
	if (!str)
		return (NULL);
	while (s[i] != '\0' && s[i] != (char)c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
