/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:37:38 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:37:39 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	letter;
	unsigned char	*str;

	str = (unsigned char*)b;
	letter = (unsigned char)c;
	while (len)
	{
		len--;
		str[len] = letter;
	}
	return (b);
}
