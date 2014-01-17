/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 12:08:25 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/17 14:12:30 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	quit_wolf(t_wolf *wolf)
{
	SDL_DestroyWindow(wolf->window);
	SDL_FreeSurface(wolf->surface);
	SDL_DestroyRenderer(wolf->renderer);
	SDL_Quit();
}
