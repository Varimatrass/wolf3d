/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 06:34:27 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/17 06:34:28 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_exp(int a, int ex)
{
	double	ret;

	if (ex == 0)
		return (1);
	if (ex > 0)
	{
		ret = (double)a;
		while (--ex)
			ret *= (double)a;
	}
	else
	{
		ret = 1.0;
		while (ex++)
			ret /= (double)a;
	}
	return (ret);
}
