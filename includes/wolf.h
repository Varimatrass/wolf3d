/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:26:47 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/16 13:33:03 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "SDL.h"

# include "SDL.h"
/*
** i don't know
*/
# include "SDL/SDL_image.h"
# include "SDL/SDL_ttf.h"
# include <string>
/*
** end
*/

typedef struct	s_vars
{
	t_x_and_y	*pos;
	t_x_and_y	*dir;
	t_x_and_y	*plane;
	t_x_and_y	*ray_pos;
	t_x_and_y	*ray_dir;

	double		cameraX;

	double		time;
	double		oldTime;


			double sideDistX;
			double sideDistY;

			//length of ray from one x or y-side to next x or y-side
			double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
			double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
			double perpWallDist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepX;
			int stepY;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?


			int lineHeight = abs(int(h / perpWallDist));

			//calculate lowest and highest pixel to fill in current stripe
			int drawStart = -lineHeight / 2 + h / 2;
			if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + h / 2;
			if(drawEnd >= h)drawEnd = h - 1;

			ColorRGB color;

		double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds

		double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
		double rotSpeed = frameTime * 3.0; //the constant value is in radians/second


			double oldDirX = dirX;
			double oldPlaneX = planeX;



}				t_vars;

typedef struct	s_x_and_y
{
	double		x;
	double		y;
}				t_x_and_y;
# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200

#endif /* !WOLF_H */
