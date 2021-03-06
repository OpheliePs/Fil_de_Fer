/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:45:27 by opettex-          #+#    #+#             */
/*   Updated: 2016/01/21 20:52:49 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(double nb)
{
	double i;

	i = 0;
	if (nb == 0)
		return (0);
	if (nb < 0)
		return (0. / 0.);
	while (i * i < nb)
		i++;
	return (i);
}
