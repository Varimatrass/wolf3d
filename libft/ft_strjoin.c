/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:41:15 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:41:15 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = ft_strcpy(ret, s1);
	return (ft_strcat(ret, s2));
}
