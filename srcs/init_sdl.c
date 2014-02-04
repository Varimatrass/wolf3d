/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 00:18:41 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/18 00:19:36 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool	init_SDL(void)
{
	bool	success;

	success = true;
	if ( SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		sdl_error(E_SDL_INIT);
		success = false;
	}
	return (success);
}

void	sdl_error(const char *ERROR)
{
	ft_putstr_fd(ERROR ,2);
	ft_putendl_fd(SDL_GetError(), 2);
}

SDL_Surface			*create_surface(int width, int height)
{
	SDL_Surface	*surface;

	surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	if(surface == NULL) {
		sdl_error(E_SDL_CREATE_SUR);
		exit(1);
	}
	return (surface);
}
