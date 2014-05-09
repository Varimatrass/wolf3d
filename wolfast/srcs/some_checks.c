/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:16:56 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/18 18:18:09 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		check_victory(t_env *e)
{
	int			i;
	int			win;

	i = -1;
	win = 1;
	while (++i < e->sprites_nbr)
	{
		if (e->sprite_tab[i].tex_id == 10
			|| e->sprite_tab[i].tex_id == 11
			|| e->sprite_tab[i].tex_id == 12)
		{
			if (e->sprite_tab[i].plane_x != 3)
				win = 0;
		}
	}
	if (win)
	{
		e->p.life = 100;
		e->vict = 1;
		end_to_img(e);
	}
}

void		put_img(t_env *e)
{
	if (e->p.life < 5)
		dead_clear_img(e);
	check_victory(e);
	if (!e->p.life && !e->vict)
	{
		e->move.fwd = 0;
		e->move.bwd = 0;
		e->move.rlft = 0;
		e->move.rrgt = 0;
		e->move.slft = 0;
		e->move.srgt = 0;
		end_to_img(e);
	}
	mlx_put_image_to_window(e->mlx, e->win, e->im_tmp, 0, 0);
}

void		init_moves(t_env *e)
{
	basic_ai(e);
	apply_rot(e);
	apply_move(e);
	apply_strafing(e);
	eat_cookies(e);
}

/*
** the main function to create the whole image
*/
int			draw(t_env *e)
{
	t_trac_data	d;
	t_obj		ray;

	init_moves(e);
	d.x = -1;
	while (++(d.x) < SCREEN_WIDTH)
	{
		tracing_and_ray_init(e, &d, &ray);
		calculating_steps(&d, &ray);
		searching_wall(e, &d, &ray);
		calculating_distances(e, &d, &ray);
		d.tex_id = d.wall_type - 1;
		d.tex_id = (d.tex_id > 18) ? 0 : d.tex_id;
		if (e->p.pos_x < 25)
			draw_skybox(e, &d, &ray);
		draw_wall(e, &d, &ray);
		get_floor(e, &d, &ray);
		if (d.door_hit)
			draw_door(e, &d);
		d.z_buffer[d.x] = (d.door_hit && d.dtex_x > 0) ? d.perp_door_dist
			: d.perp_wall_dist;
	}
	sprite_casting(e, &d);
	put_img(e);
	return (0);
}

int			key_hook_r(int keycode, t_env *e)
{
	if (keycode == 65362 || keycode == 122 || keycode == 119)
		e->move.fwd = 0;
	if (keycode == 65364 || keycode == 115)
		e->move.bwd = 0;
	if (keycode == 65361)
		e->move.rlft = 0;
	if (keycode == 65363)
		e->move.rrgt = 0;
	if (keycode == 100)
		e->move.slft = 0;
	if (keycode == 97 || keycode == 113)
		e->move.srgt = 0;
	return (0);
}
