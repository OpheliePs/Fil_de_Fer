/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:34:17 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/08 12:51:10 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_nbdigits(int n)
{
	int				i;

	i = 1;
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	int				len;
	char			*str;
	unsigned int	nb;

	nb = n;
	len = ft_nbdigits(nb);
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	str[--len] = nb % 10 + 48;
	while (nb /= 10)
	{
		str[--len] = nb % 10 + 48;
	}
	if (n < 0)
	{
		str[0] = '-';
	}
	return (str);
}
