/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 13:41:58 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/09 13:41:59 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_tan_d(double degree)
{
	if (ft_cos_d(degree) != 0)
		return (ft_sin_d(degree) / ft_cos_d(degree));
	else
		return (ft_sin_d(degree) / 0.0000001);
}

double	ft_tan(double radian)
{
	if (ft_cos(radian) != 0)
		return (ft_sin(radian) / ft_cos(radian));
	else
		return (ft_sin(radian) / 0.0000001);
}
