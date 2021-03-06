/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:37:12 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:37:12 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*ret;

	ret = s1;
	while (n)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
		n--;
	}
	return (ret);
}
