/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 14:08:28 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/24 13:53:25 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *alst;
	if (list)
	{
		del(list->content, list->content_size);
		if (list->next != NULL)
			ft_lstdel(&(*alst)->next, del);
		free(list);
		*alst = (NULL);
	}
}
