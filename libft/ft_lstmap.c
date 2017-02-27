/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:18:40 by opettex-          #+#    #+#             */
/*   Updated: 2016/01/18 16:38:23 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f) (t_list *elem))
{
	t_list	*first;
	t_list	*temp;
	t_list	*temp2;

	if (lst && f)
	{
		temp = f(lst);
		first = ft_lstnew(temp->content, temp->content_size);
		lst = lst->next;
		temp2 = first;
		while (lst)
		{
			temp = f(lst);
			temp2->next = ft_lstnew(temp->content, temp->content_size);
			lst = lst->next;
			temp2 = temp2->next;
		}
		return (first);
	}
	return (NULL);
}
