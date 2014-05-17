/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:36:33 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:36:33 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*ct;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (content != NULL)
	{
		ct = malloc(content_size);
		ct = ft_memcpy(ct, content, content_size);
	}
	if (tmp)
	{
		tmp->content = (content == NULL) ? NULL : ct;
		tmp->content_size = (content == NULL) ? 0 : content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
