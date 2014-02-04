/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:08:13 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/18 00:11:03 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_vars			*init_vars(t_vars *vars)
{
	vars->pos.x = 22;
	vars->pos.y = 12;
	vars->dir.x = -1;
	vars->dir.y = 0;
	vars->plane.x = 0;
	vars->plane.y = 0.66;
	vars->time = 0;
	vars->old_time = 0;
	return (vars);
}

void			init_wolf(uint32_t height, uint32_t width, t_wolf *wolf)
{
	init_SDL();
	if ((wolf->window = create_window(width, height, "wolf3d")) == NULL)
	{
		sdl_error(E_SDL_WIN);
		exit(1);
	}
	if ((wolf->renderer = create_renderer(wolf->window)) == NULL)
	{
		sdl_error(E_SDL_CREATE_REN);
		exit(1);
	}
}

SDL_Window		*create_window(int width, int height, const char *title)
{
	SDL_Window	*window;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
											SDL_WINDOWPOS_UNDEFINED,
											width, height, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		sdl_error(E_SDL_WIN);
	}
	return (window);
}

SDL_Renderer	*create_renderer(SDL_Window *window)
{
	SDL_Renderer	*ren;

	ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
									| SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		sdl_error(E_SDL_CREATE_REN);
	}
	return (ren);
}
