/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:15:37 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/17 12:36:52 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SDL.h"

#ifndef WOLF_STRUCT_H
# define WOLF_STRUCT_H

typedef struct		s_wolf
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
}					t_wolf;

typedef struct	s_dbl_coo
{
	double		x;
	double		y;
}				t_dbl_coo;

typedef struct	s_int_coo
{
	int			x;
	int			y;
}				t_int_coo;

typedef struct	s_vars
{
	t_dbl_coo	pos;
	t_dbl_coo	dir;
	t_dbl_coo	plane;
	t_dbl_coo	ray_pos;
	t_dbl_coo	ray_dir;
	t_dbl_coo	side_dist;
	t_dbl_coo	delta_dist;
	t_int_coo	map;
	t_int_coo	step;

	double		cameraX;
	double		time;
	double		oldTime;
	double perpWallDist;

	double frameTime;
	double moveSpeed;
	double rotSpeed;

	double oldDirX;
	double oldPlaneX;

	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
}				t_vars;

#endif /* !WOLF_STRUCT_H */
