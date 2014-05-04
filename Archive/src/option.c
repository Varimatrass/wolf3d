/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 18:16:13 by tbalea            #+#    #+#             */
/*   Updated: 2014/01/18 23:06:47 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tab.h"

t_color	color_env(void)
{
	t_color	color;

	color.sky = 0x723E64;
	color.walw = 0xFF0000;
	color.wale = 0x00FF00;
	color.wals = 0x0000FF;
	color.waln = 0x26619C;
	color.earth = 0x1B4F08;
	return (color);
}

t_size	size_win(void)
{
	t_size	size;

	size.x = 320;
	size.y = 320;
	return (size);
}

char	*name_win(void)
{
	char	*name;

	name = "Wolf3D";
	return (name);
}

t_max	max_wall(t_size size)
{
	t_max	max;

	max.max = size.x / 8;
	max.mxwl = size.y * 6;
	max.mxwl = max.mxwl / 5;
	return (max);
}

t_touch	touch(void)
{
	t_touch	touch;

	touch.esc = 65307;
	touch.w = 119;
	touch.a = 97;
	touch.s = 115;
	touch.d = 100;
	return (touch);
}
