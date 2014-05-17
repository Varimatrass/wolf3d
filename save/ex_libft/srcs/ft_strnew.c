/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:08:42 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/08 19:56:32 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char*)malloc(size * sizeof(char))) == NULL)
		return (NULL);
	s = ft_memset(s, 0, size);
	return (s);
}
