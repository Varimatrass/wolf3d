/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 16:26:47 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/01/17 14:14:48 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "wolf_struct.h"
# include "SDL.h"

/*
** i don't know
**# include <string>
*/

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WIN_HEIGHT 1200
# define WIN_WIDTH 1200

void			wolf3d(t_vars *vars, bool done, t_wolf wolf);
t_vars			*init_pos_dir_plane(t_vars *vars);
void			init_wolf(uint32_t height, uint32_t width, t_wolf *wolf);
SDL_Window		*create_window(int width, int height, const char *title);
SDL_Renderer	*create_renderer(SDL_Window *window);
void			quit_wolf(t_wolf *wolf);

#endif /* !WOLF_H */
