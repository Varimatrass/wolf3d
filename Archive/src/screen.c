/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 17:17:55 by tbalea            #+#    #+#             */
/*   Updated: 2014/05/09 13:21:15 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "tab.h"

void	draw_earthnsky(t_win win, t_size siz)
{
	int				y;
	int				x;
	t_color			color;

	color = color_env();
	y = siz.y / 2;
	while (y <= siz.y)
	{
		x = 0;
		while (x <= siz.x)
		{
			mlx_pixel_put(win.mlx, win.win, x, y, color.earth);
			mlx_pixel_put(win.mlx, win.win, x, (y - (siz.y / 2)), color.sky);
			x++;
		}
		y++;
	}
}

void	draw_wall(t_win w, t_size siz, t_wall wal)
{
	int		i;
	int		y;
	int		x;
	int		clr;
	t_max	max;

	i = 0;
	max = max_wall(siz);
	while (i < max.max)
	{
		y = 0;
		clr = which_color(wal.clor[i]);
		while (y <= max.mxwl / 2 - wal.rang[i]/ 2)
		{
			x = (i * (siz.x / max.max));
			while (x <= ((siz.x / max.max) + (i * (siz.x / max.max))))
			{
				mlx_pixel_put(w.mlx, w.win, x, (y + siz.y / 2), clr);
				mlx_pixel_put(w.mlx, w.win, x, - (y - (max.mxwl / 2)), clr);
				x++;
			}
			y++;
		}
		i++;
	}
}

t_wall	ray_casting(t_wolf wol, t_wall wal, t_max max, t_size siz)
{
	t_size	di;
	t_size	xray;
	t_ray	ray;

	wal.clor = (int *)malloc(sizeof(int) * max.max);
	di.y = -1;
	while (di.y++ < max.max)
	{
		di.x = -1;
		ray.ray = (di.y * (3.1415926 / (3 * max.max))) - (3.1415926 / 6);
		ray.crash = -1;
		while (ray.crash == -1 && di.x++ <= siz.y)
		{
			xray.x = wol.posx + di.x * (cos(wol.pi + ray.ray));
			xray.y = wol.posy + di.x * (sin(wol.pi + ray.ray));
			if (wal.lab[xray.y / 64][xray.x / 64] == '1' || di.x == siz.y
				|| wal.lab[xray.y / 64][xray.x / 64] == '\0')
			{
				wal.rang[di.y] = di.x;
				ray.crash = wall_color(xray, wal, wol.pi, ray.ray);
				wal.clor[di.y] = ray.crash;
			}
		}
	}
	return (wal);
}

int		wall_color(t_size ray, t_wall wal, float wol, float wra)
{
	int		sens;

	sens = 0;
	if (cos(wol + wra) < 0)
		sens = -1;
	if (cos(wol + wra) > 0)
		sens = 1;
	if (wal.lab[ray.y / 64][(ray.x - sens) / 64] == '0')
	{
		if (cos(wol + wra) > 0)
			return (2);
		return (1);
	}
	else if (sin(wol + wra) > 0)
		return (3);
	return (0);
}

void	draw(t_wolf wol, t_wall wal, t_win win, t_size siz)
{
	t_max	max;
/*
	int		i;
	t_color	c;
*/

	wal.rang = (int *)malloc(sizeof(int) * max.max);
/*
	i = 0;
	c = color_env();
*/
	max = max_wall(siz);
	draw_earthnsky(win, siz);
	wal = ray_casting(wol, wal, max, siz);
	draw_wall(win, siz, wal);
}
