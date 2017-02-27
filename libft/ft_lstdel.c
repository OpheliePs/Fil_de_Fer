/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:31:39 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/07 18:05:41 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *temp;

	while ((*alst) != NULL)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, del);
		(*alst) = temp;
	}
}
