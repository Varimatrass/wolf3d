/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:08:25 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/17 12:18:03 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf3d_quit(t_wolf3d *wolf3d)
{
	SDL_DestroyWindow(wolf3d->window);
	SDL_FreeSurface(wolf3d->surface);
	SDL_DestroyRenderer(wolf3d->renderer);
	SDL_Quit();
}
