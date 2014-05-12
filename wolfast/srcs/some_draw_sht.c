/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_draw_sht.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:52:40 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 13:52:41 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_floor(t_env *e, t_trac_data *d, t_obj *ray)
{
	if (d->side == 0 && ray->dir_x > 0)
	{
		d->floor_x_wall = d->map_x;
		d->floor_y_wall = d->map_y + d->wall_x;
	}
	else if (d->side == 0 && ray->dir_x < 0)
	{
		d->floor_x_wall = d->map_x + 1.0;
		d->floor_y_wall = d->map_y + d->wall_x;
	}
	else if (d->side == 1 && ray->dir_y > 0)
	{
		d->floor_x_wall = d->map_x + d->wall_x;
		d->floor_y_wall = d->map_y;
	}
	else
	{
		d->floor_x_wall = d->map_x + d->wall_x;
		d->floor_y_wall = d->map_y + 1.0;
	}
	draw_floor(e, d);
}

double		vdir_to_degree(double dir_x, double dir_y)
{
	double	result;

	if (dir_x != 0)
		result = atan(dir_y / dir_x) * 180.0 / PI;
	else
	{
		if (dir_y > 0)
			result = 90;
		else
			result = -90;
	}
	if (result < 0)
		result = 180 + result;
	if (dir_y <= 0)
		result = 180 + result;
	return (result);
}

void		draw_skybox(t_env *e, t_trac_data *d, t_obj *ray)
{
	int				i;
	int				sky_x;
	int				sky_y;
	t_colors		col;

	sky_x = (int)vdir_to_degree(ray->dir_x, ray->dir_y);
	sky_x = (int)(((double)sky_x / 360.0) * SKY_WIDTH);
	sky_x = SKY_WIDTH - sky_x;
	i = 0;
	while (i < SCREEN_HEIGHT / 2)
	{
		sky_y = ((double)i / ((double)SCREEN_HEIGHT / 2.0)) * SKY_HEIGHT;
		col.b = e->skybox.data[sky_y * e->skybox.sizeline
								+ (e->skybox.bpp / 8) * sky_x];
		col.g = e->skybox.data[sky_y * e->skybox.sizeline
								+ (e->skybox.bpp / 8) * sky_x + 1];
		col.r = e->skybox.data[sky_y * e->skybox.sizeline
								+ (e->skybox.bpp / 8) * sky_x + 2];
		e->data[i * e->sizeline + d->x * (e->bpp / 8)] = col.b;
		e->data[i * e->sizeline + d->x * (e->bpp / 8) + 1] = col.g;
		e->data[i * e->sizeline + d->x * (e->bpp / 8) + 2] = col.r;
		i++;
	}
}

void		draw_door(t_env *e, t_trac_data *d)
{
	int				i;
	t_colors		col;

	d->draw_start = -d->dline_height / 2 + SCREEN_HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->dline_height / 2 + SCREEN_HEIGHT / 2;
	if (d->draw_end > SCREEN_HEIGHT)
		d->draw_end = SCREEN_HEIGHT;
	i = d->draw_start - 1;
	d->dtex_x -= e->door;
	while (++i < d->draw_end)
	{
		get_door_color(e, d, i, &col);
		if (col.b || col.g || col.r)
		{
			e->data[i * e->sizeline + d->x * (e->bpp / 8)] = col.b;
			e->data[i * e->sizeline + d->x * (e->bpp / 8) + 1] = col.g;
			e->data[i * e->sizeline + d->x * (e->bpp / 8) + 2] = col.r;
		}
	}
}

void		draw_wall(t_env *e, t_trac_data *d, t_obj *ray)
{
	int				i;
	t_colors		col;

	d->draw_start = -d->line_height / 2 + SCREEN_HEIGHT / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + SCREEN_HEIGHT / 2;
	if (d->draw_end > SCREEN_HEIGHT)
		d->draw_end = SCREEN_HEIGHT;
	i = d->draw_start - 1;
	while (++i < d->draw_end)
	{
		get_pixel_color(e, d, i, &col);
		apply_shadow(d, ray, &col);
		if ((d->tex_id != 1 && d->tex_id != 0) || col.b || col.g || col.r)
		{
			e->data[i * e->sizeline + d->x * (e->bpp / 8)] = col.b;
			e->data[i * e->sizeline + d->x * (e->bpp / 8) + 1] = col.g;
			e->data[i * e->sizeline + d->x * (e->bpp / 8) + 2] = col.r;
		}
	}
}
