/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:33:52 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:33:54 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit (str[i]) != 0)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}
