/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 04:25:41 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/14 11:11:42 by matthias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		if ((new_list->content = (void *)ft_memalloc(content_size)) != NULL)
			ft_memcpy(new_list->content, content, content_size);
		else
		{
			free(new_list);
			return (NULL);
		}
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	return (new_list);
}
