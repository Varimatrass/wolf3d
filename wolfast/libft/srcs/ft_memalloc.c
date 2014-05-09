/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:07:46 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/06 13:39:39 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	fresh_mem = NULL;
	if (size)
	{
		fresh_mem = (void *)malloc(size);
		if (fresh_mem == NULL)
			return (NULL);
		else
		{
			ft_bzero(fresh_mem, size);
			return (fresh_mem);
		}
	}
	else
		return (NULL);
}
