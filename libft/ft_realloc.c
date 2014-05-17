/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:39:09 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:39:10 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, size_t n)
{
	void	*copy;

	copy = malloc(n);
	if (s != NULL)
	{
		copy = ft_memcpy(copy, s, n);
		free(s);
	}
	return (copy);
}
