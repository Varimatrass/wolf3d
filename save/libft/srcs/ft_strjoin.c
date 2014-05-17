/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 23:14:05 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/08 20:58:38 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*join;

	i = 0;
	j = 0;
	k = 0;
	join = NULL;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if ((join = (char *)malloc((i + j + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (k < i + j)
	{
		if (k < i)
			join[k] = s1[k];
		else
			join[k] = s2[k - i];
		k++;
	}
	join[k] = 0;
	return (join);
}
