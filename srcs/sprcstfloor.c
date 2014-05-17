/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprcstfloor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:54:34 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 13:54:37 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		showgun(t_env *e)
{
	static int	ct = 0;

	move_bullets(e);
	if (ct == 5 && !(ct = 0))
		e->shooting = 0;
	if (e->shooting == 1)
	{
		ct++;
		if (ct == 1)
		{
			add_one_obj_tab(e);
			e->sprite_tab[e->sprites_nbr - 1].life = 0;
			e->sprite_tab[e->sprites_nbr - 1].pos_x = e->p.pos_x
				+ 0.5 * e->p.dir_x;
			e->sprite_tab[e->sprites_nbr - 1].pos_y = e->p.pos_y
				+ 0.5 * e->p.dir_y;
			e->sprite_tab[e->sprites_nbr - 1].dir_x = e->p.dir_x;
			e->sprite_tab[e->sprites_nbr - 1].dir_y = e->p.dir_y;
			e->sprite_tab[e->sprites_nbr - 1].plane_x = 0;
			e->sprite_tab[e->sprites_nbr - 1].plane_y = 1;
			e->sprite_tab[e->sprites_nbr - 1].tex_id = 13;
		}
	}
}

void		sprite_casting(t_env *e, t_trac_data *d)
{
	t_spricast	va;

	showgun(e);
	init_sprite_tab(e);
	sort_tab(e);
	va.i = -1;
	while (++(va.i) < e->sprites_nbr)
	{
		set_trans_xy(e, &va);
		set_sprite_draw_strt_nd(&va, d, e);
		d->x = d->draw_start - 1;
		while (++(d->x) < d->draw_end)
			print_my_sprite(e, d, &va);
	}
	gun_to_img(e);
}

void		floor_pixel_color(t_env *e, int x, int y, t_colors *col)
{
	int		id;

	id = (e->p.pos_x > 25) ? 2 : 9;
	col->b = ((e->tex_tab)[id].data)[(y * (e->tex_tab)[id].sizeline
										+ ((e->tex_tab)[id].bpp / 8) * x)];
	col->g = ((e->tex_tab)[id].data)[(y * (e->tex_tab)[id].sizeline
										+ ((e->tex_tab)[id].bpp / 8) * x) + 1];
	col->r = ((e->tex_tab)[id].data)[(y * (e->tex_tab)[id].sizeline
										+ ((e->tex_tab)[id].bpp / 8) * x) + 2];
}

void		print_floor(t_env *e, t_trac_data *d, t_colors *col, int y)
{
	e->data[y * e->sizeline + d->x * (e->bpp / 8)] = col->b;
	e->data[y * e->sizeline + d->x * (e->bpp / 8) + 1] = col->g;
	e->data[y * e->sizeline + d->x * (e->bpp / 8) + 2] = col->r;
	if (e->p.pos_x > 25)
	{
		e->data[(SCREEN_HEIGHT - (y + 1)) * e->sizeline
				+ d->x * (e->bpp / 8)] = col->b * 1.25;
		e->data[(SCREEN_HEIGHT - (y + 1)) * e->sizeline
				+ d->x * (e->bpp / 8) + 1] = col->g * 1.25;
		e->data[(SCREEN_HEIGHT - (y + 1)) * e->sizeline
				+ d->x * (e->bpp / 8) + 2] = col->r * 1.25;
	}
}

void		draw_floor(t_env *e, t_trac_data *d)
{
	int				floor_tex_x;
	int				floor_tex_y;
	int				y;
	t_colors		col;

	d->dist_wall = d->perp_wall_dist;
	d->dist_player = 0.0;
	if (d->draw_end < 0)
		d->draw_end = SCREEN_HEIGHT;
	y = d->draw_end - 1;
	while (++y < SCREEN_HEIGHT)
	{
		d->current_dist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		d->weight = (d->current_dist - d->dist_player)
			/ (d->dist_wall - d->dist_player);
		d->current_floor_x = d->weight * d->floor_x_wall
			+ (1.0 - d->weight) * e->p.pos_x;
		d->current_floor_y = d->weight * d->floor_y_wall
			+ (1.0 - d->weight) * e->p.pos_y;
		floor_tex_x = ft_abs((int)(d->current_floor_x * TEX_WIDTH) % TEX_WIDTH);
		floor_tex_y = ft_abs((int)(d->current_floor_y
									* TEX_HEIGHT) % TEX_HEIGHT);
		floor_pixel_color(e, floor_tex_x, floor_tex_y, &col);
		print_floor(e, d, &col, y);
	}
}
