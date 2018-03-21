/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-souz <fde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:08:40 by fde-souz          #+#    #+#             */
/*   Updated: 2017/11/13 15:19:41 by fde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		start = new;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
