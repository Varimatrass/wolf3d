/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:08:31 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/19 16:59:30 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		tracing_and_ray_init(t_env *e, t_trac_data *d, t_obj *ray)
{
	d->camera_x = 2 * d->x / (double)(SCREEN_WIDTH) - 1;
	ray->pos_x = e->p.pos_x;
	ray->pos_y = e->p.pos_y;
	ray->dir_x = e->p.dir_x + e->p.plane_x * d->camera_x;
	ray->dir_y = e->p.dir_y + e->p.plane_y * d->camera_x;
	d->map_x = (int)(ray->pos_x);
	d->map_y = (int)(ray->pos_y);
	d->delta_dist_x = sqrt((1 + (ray->dir_y * ray->dir_y)
							/ (ray->dir_x * ray->dir_x)));
	d->delta_dist_y = sqrt((1 + (ray->dir_x * ray->dir_x)
							/ (ray->dir_y * ray->dir_y)));
	d->hit = 0;
	d->door_hit = 0;
}

void		calculating_steps(t_trac_data *d, t_obj *ray)
{
	if (ray->dir_x < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (ray->pos_x - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - ray->pos_x) * d->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (ray->pos_y - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - ray->pos_y) * d->delta_dist_y;
	}
}

void		calc_door_dist(t_env *e, t_trac_data *d, t_obj *ray)
{
	d->door_hit = 1;
	if (d->side == 0)
		d->perp_door_dist = fabs((d->map_x - ray->pos_x
									+ (1 - d->step_x) / 2) / ray->dir_x);
	else
		d->perp_door_dist = fabs((d->map_y - ray->pos_y
									+ (1 - d->step_y) / 2) / ray->dir_y);
	d->dline_height = ft_abs((int)(SCREEN_HEIGHT / d->perp_door_dist));
	d->door_type = ft_atoi((char *)&e->world[d->map_x][d->map_y][1]);
	if (d->side == 1)
		d->door_x = ray->pos_x
			+ ((d->map_y - ray->pos_y
				+ (1 - d->step_y) / 2) / ray->dir_y) * ray->dir_x;
	else
		d->door_x = ray->pos_y
			+ ((d->map_x - ray->pos_x
				+ (1 - d->step_x) / 2) / ray->dir_x) * ray->dir_y;
	d->door_x -= floor((d->door_x));
	d->dtex_x = (int)(d->door_x * (double)(TEX_WIDTH));
	if (d->side == 0 && ray->dir_x > 0)
		d->dtex_x = TEX_WIDTH - d->dtex_x - 1;
	if (d->side == 1 && ray->dir_y < 0)
		d->dtex_x = TEX_WIDTH - d->dtex_x - 1;
}

void		searching_wall(t_env *e, t_trac_data *d, t_obj *ray)
{
	while (d->hit == 0)
	{
		if (d->side_dist_x < d->side_dist_y)
		{
			d->side_dist_x += d->delta_dist_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_dist_y += d->delta_dist_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (ft_atoi(e->world[d->map_x][d->map_y]))
			d->hit = 1;
		if (e->world[d->map_x][d->map_y][0] == 'D')
			calc_door_dist(e, d, ray);
	}
}

void		calculating_distances(t_env *e, t_trac_data *d, t_obj *ray)
{
	if (d->side == 0)
		d->perp_wall_dist = fabs((d->map_x - ray->pos_x
									+ (1 - d->step_x) / 2) / ray->dir_x);
	else
		d->perp_wall_dist = fabs((d->map_y - ray->pos_y
									+ (1 - d->step_y) / 2) / ray->dir_y);
	d->line_height = ft_abs((int)(SCREEN_HEIGHT / d->perp_wall_dist));
	d->wall_type = ft_atoi(e->world[d->map_x][d->map_y]);
	if (d->side == 1)
		d->wall_x = ray->pos_x
			+ ((d->map_y - ray->pos_y
				+ (1 - d->step_y) / 2) / ray->dir_y) * ray->dir_x;
	else
		d->wall_x = ray->pos_y
			+ ((d->map_x - ray->pos_x
				+ (1 - d->step_x) / 2) / ray->dir_x) * ray->dir_y;
	d->wall_x -= floor((d->wall_x));
	d->tex_x = (int)(d->wall_x * (double)(TEX_WIDTH));
	if (d->side == 0 && ray->dir_x > 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
	if (d->side == 1 && ray->dir_y < 0)
		d->tex_x = TEX_WIDTH - d->tex_x - 1;
}
