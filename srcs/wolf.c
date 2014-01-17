/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:29:27 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/17 15:56:33 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf3d(t_vars *vars, bool done, t_wolf wolf)
{
	size_t	x;

	x = 0;
	while (x < W)
	{
		calcs(vars, x);
		test_ray_dir(vars);
		test_hit(vars);


		if (side == 0)
			perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
		else
			perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);
		int lineHeight = abs(int(h / perpWallDist));
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)drawEnd = h - 1;
		ColorRGB color;
		switch(worldMap[mapX][mapY])
		{
		case 1:  color = RGB_Red;  break; //red
		case 2:  color = RGB_Green;  break; //green
		case 3:  color = RGB_Blue;   break; //blue
		case 4:  color = RGB_White;  break; //white
		default: color = RGB_Yellow; break; //yellow
		}
		if (side == 1) {color = color / 2;}
		verLine(x, drawStart, drawEnd, color);
	}

/*end of while*/

	oldTime = time;
	time = getTicks();
	double frameTime = (time - oldTime) / 1000.0;
	print(1.0 / frameTime);
	redraw();
	cls();
	double moveSpeed = frameTime * 5.0;
	double rotSpeed = frameTime * 3.0;
	readKeys();
	if (keyDown(SDLK_UP))
	{
		if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
	}
	if (keyDown(SDLK_DOWN))
	{
		if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
		if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
	}
	if (keyDown(SDLK_RIGHT))
	{
		double oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
	if (keyDown(SDLK_LEFT))
	{
		double oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		double oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}

/*--------------------------------------------------------------------------------------------------------------------------------------------*/

		x++;
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
		if (worldMap[vars->map.x][vars->map.y] > 0) hit = 1;
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

	camera = 2 * x / double(W) - 1;
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
