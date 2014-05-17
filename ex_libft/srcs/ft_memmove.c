/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 22:57:39 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/01 16:59:50 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if ((tmp = (char *)malloc(n * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	free(tmp);
	return (s1);
}
