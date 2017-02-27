/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:13:13 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 17:03:46 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*dst;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(dst = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	j--;
	while (dst[j] == ' ' || dst[j] == '\n' || dst[j] == '\t')
		dst[j--] = '\0';
	return (dst);
}
