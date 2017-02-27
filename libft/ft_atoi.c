/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:49:27 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/09 13:48:13 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int	rlt;
	int negatif;

	i = 0;
	rlt = 0;
	negatif = 0;
	while (str[i] == (' ') || str[i] == '\t' || str[i] == '\n'
				|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == ('-'))
		negatif = 1;
	if (str[i] == '+' || negatif)
		i++;
	while (ft_isdigit(str[i]))
	{
		rlt = rlt * 10 + str[i] - '0';
		i++;
	}
	rlt = (negatif == 1) ? -rlt : rlt;
	return (rlt);
}
