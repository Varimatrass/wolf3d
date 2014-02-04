/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:29:27 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/18 00:55:27 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf3d(t_vars *vars, bool done, t_wolf *wolf)
{
	size_t	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		calcs(vars, x);
		test_ray_dir(vars);
		test_hit(vars);

		if (vars->side == 0)
			vars->perp_wall_dist = fabs((vars->map.x - vars->ray_pos.x + (1 - vars->step.x) / 2) / vars->ray_dir.x);
		else
			vars->perp_wall_dist = fabs((vars->map.y - vars->ray_pos.y + (1 - vars->step.y) / 2) / vars->ray_dir.y);

		vars->line_height = abs(int(h / vars->perp_wall_dist));
		vars->draw_start = -(vars->line_height) / 2 + h / 2;
		if(vars->draw_start < 0)
			vars->draw_start = 0;
		vars->draw_end = vars->line_height / 2 + h / 2;
		if(vars->draw_end >= h)
			vars->draw_end = h - 1;

		ColorRGB color;
		switch(map[mapX][mapY])
		{
		case 1:  color = RGB_Red;  break; //red
		case 2:  color = RGB_Green;  break; //green
		case 3:  color = RGB_Blue;   break; //blue
		case 4:  color = RGB_White;  break; //white
		default: color = RGB_Yellow; break; //yellow
		}

		if (vars->side == 1) {color = color / 2;}
		verLine(x, vars->draw_start, vars->draw_end, color);

		x++;
	}

	vars->old_time = vars->time;
	vars->time = getTicks();
	vars->frame_time = (vars->time - vars->old_time) / 1000.0;
	print(1.0 / vars->frame_time);
	redraw();
	cls();
	vars->move_speed = vars->frame_time * 5.0;
	vars->rot_speed = vars->frame_time * 3.0;
	readKeys();
	if (keyDown(SDLK_UP))
	{
		if(map[int(vars->pos.x + vars->dir.x * vars->move_speed)][int(vars->pos.y)] == false)
			vars->pos.x += vars->dir.x * vars->move_speed;
		if(map[int(vars->pos.x)][int(vars->pos.y + vars->dir.y * vars->move_speed)] == false)
			vars->pos.y += vars->dir.y * vars->move_speed;
	}
	if (keyDown(SDLK_DOWN))
	{
		if(map[int(vars->pos.x - vars->dir.x * vars->move_speed)][int(vars->pos.y)] == false)
			vars->pos.x -= vars->dir.x * vars->move_speed;
		if(map[int(vars->pos.x)][int(vars->pos.y - vars->dir.y * vars->move_speed)] == false)
			vars->pos.y -= vars->dir.y * vars->move_speed;
	}
	if (keyDown(SDLK_RIGHT))
	{
		vars->old_dirx = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(-(vars->rot_speed)) - vars->dir.y * sin(-(vars->rot_speed));
		vars->dir.y = vars->old_dirx * sin(-(vars->rot_speed)) + vars->dir.y * cos(-(vars->rot_speed));
		vars->old_planex = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(-(vars->rot_speed)) - vars->plane.y * sin(-(vars->rot_speed));
		vars->plane.y = vars->old_planex * sin(-(vars->rot_speed)) + vars->plane.y * cos(-(vars->rot_speed));
	}
	if (keyDown(SDLK_LEFT))
	{
		vars->old_dirx = vars->dir.x;
		vars->dir.x = vars->dir.x * cos(vars->rot_speed) - vars->dir.y * sin(vars->rot_speed);
		vars->dir.y = vars->old_dirx * sin(vars->rot_speed) + vars->dir.y * cos(vars->rot_speed);
		vars->old_planex = vars->plane.x;
		vars->plane.x = vars->plane.x * cos(vars->rot_speed) - vars->plane.y * sin(vars->rot_speed);
		vars->plane.y = vars->old_planex * sin(vars->rot_speed) + vars->plane.y * cos(vars->rot_speed);
	}

}

void	test_hit(t_vars vars)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (vars->side_dist.x < vars->side_dist.y)
		{
			vars->side_dist.x += vars->delta_dist.x;
			vars->map.x += vars->step.x;
			vars->side = 0;
		}
		else
		{
			vars->side_dist.y += vars->delta_dist.y;
			vars->map.y += vars->step.y;
			vars->side = 1;
		}
		if (map[vars->map.x][vars->map.y] > 0) hit = 1;
	}
}

void	test_ray_dir(t_vars vars)
{
	if (vars->ray_dir.x < 0)
	{
		vars->step.x = -1;
		vars->side_dist.x = (vars->ray_pos.x - vars->map.x) * vars->delta_dist.x;
	}
	else
	{
		vars->step.x = 1;
		vars->side_dist.x = (vars->map.x + 1.0 - vars->ray_pos.x) * vars->delta_dist.x;
	}
	if (vars->ray_dir.y < 0)
	{
		vars->step.y = -1;
		vars->side_dist.y = (vars->ray_pos.y - vars->map.y) * vars->delta_dist.y;
	}
	else
	{
		vars->step.y = 1;
		vars->side_dist.y = (vars->map.y + 1.0 - vars->ray_pos.y) * vars->delta_dist.y;
	}
}

void	calcs(t_vars *vars, size_t x)
{
	double		camera;
	t_dbl_coo	ray_dir_square;

	camera = 2 * x / double(WIN_WIDTH) - 1;
	vars->ray_pos.x = vars->pos.x;
	vars->ray_pos.y = vars->pos.y;
	vars->ray_dir.x = vars->dir.x + vars->plane.x * camera;
	vars->ray_dir.y = vars->dir.y + vars->plane.y * camera;
	vars->map.x = int(vars->ray_pos.x);
	vars->map.y = int(vars->ray_pos.y);
	ray_dir_square.x = vars->ray_dir.x * vars->ray_dir.x;
	ray_dir_square.y = vars->ray_dir.y * vars->ray_dir.y;
	vars->delta_dist.x = sqrt(1 + (ray_dir_square.y) / (ray_dir_square.x));
	vars->delta_dist.y = sqrt(1 + (ray_dir_square.x) / (ray_dir_square.y));
}
