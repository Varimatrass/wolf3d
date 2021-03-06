/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:39:58 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:39:59 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	s1[i] = '\0';
	return (s1);
}
