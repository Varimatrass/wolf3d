/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:36:25 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:36:26 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;

	res = ft_lstnew((lst)->content, (lst)->content_size);
	res = f(res);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((lst)->content, (lst)->content_size);
		tmp = f(tmp);
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
