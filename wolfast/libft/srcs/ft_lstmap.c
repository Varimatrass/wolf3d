/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 04:30:37 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/04/25 14:18:16 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *d, size_t s)
{
	free(d);
	(void)s;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	lst = f(lst);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	start = new;
	while (lst->next)
	{
		lst = f(lst->next);
		if (!(new->next = ft_lstnew(lst->content, lst->content_size)))
		{
			ft_lstdel(&start, del);
			return (NULL);
		}
		new = new->next;
	}
	return (start);
}
