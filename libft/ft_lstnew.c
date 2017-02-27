/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 22:47:04 by opettex-          #+#    #+#             */
/*   Updated: 2015/12/29 14:43:02 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	maillon = malloc(sizeof(t_list));
	if (maillon == NULL)
		return (NULL);
	if (content == NULL)
	{
		maillon->content_size = 0;
		maillon->content = NULL;
	}
	else
	{
		maillon->content = malloc(content_size);
		if (maillon->content == NULL)
			return (NULL);
		ft_memcpy((maillon->content), content, content_size);
		maillon->content_size = content_size;
	}
	maillon->next = NULL;
	return (maillon);
}
