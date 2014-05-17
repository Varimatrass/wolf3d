/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:53:35 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 16:49:06 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_sprite(t_env *e, int i)
{
	if ((int)(e->sprite_tab[i].pos_x * 100) < (int)(e->p.pos_x * 100)
		&& !colision_check(e, e->sprite_tab[i].pos_x
							+ 0.5, e->sprite_tab[i].pos_y))
		e->sprite_tab[i].pos_x += 0.02;
	else if ((int)(e->sprite_tab[i].pos_x * 100)
				> (int)(e->p.pos_x * 100)
				&& !colision_check(e, e->sprite_tab[i].pos_x
									- 0.5, e->sprite_tab[i].pos_y))
		e->sprite_tab[i].pos_x -= 0.02;
	if ((int)(e->sprite_tab[i].pos_y * 100) < (int)(e->p.pos_y * 100)
		&& !colision_check(e, e->sprite_tab[i].pos_x
							, e->sprite_tab[i].pos_y + 0.5))
		e->sprite_tab[i].pos_y += 0.02;
	else if ((int)(e->sprite_tab[i].pos_y * 100)
				> (int)(e->p.pos_y * 100)
				&& !colision_check(e, e->sprite_tab[i].pos_x
									, e->sprite_tab[i].pos_y - 0.5))
		e->sprite_tab[i].pos_y -= 0.02;
}

void		monsters_attack(t_env *e, int i, double dist)
{
	add_one_obj_tab(e);
	e->sprite_tab[e->sprites_nbr - 1].life = 0;
	e->sprite_tab[e->sprites_nbr - 1].pos_x = e->sprite_tab[i].pos_x;
	e->sprite_tab[e->sprites_nbr - 1].pos_y = e->sprite_tab[i].pos_y;
	e->sprite_tab[e->sprites_nbr
					- 1].dir_x = ((e->p.pos_x
									- e->sprite_tab[i].pos_x) / dist) * 0.5;
	e->sprite_tab[e->sprites_nbr
					- 1].dir_y = ((e->p.pos_y
									- e->sprite_tab[i].pos_y) / dist) * 0.5;
	e->sprite_tab[e->sprites_nbr - 1].plane_x = 2;
	e->sprite_tab[e->sprites_nbr - 1].plane_y = 1;
	e->sprite_tab[e->sprites_nbr - 1].tex_id = 13;
}

void		open_door(t_env *e)
{
	static int	ct = 0;

	ct = (ct == 64) ? 0 : ct + 1;
	if (!(ct % 3) && e->key != 0)
	{
		if (e->op > 0 && e->door != 64)
			e->door = (e->door != 64) ? e->door + e->op : 0;
		else if (e->op < 0 && e->door != 0)
			e->door = (e->door != 0) ? e->door + e->op : 0;
	}
}

void		basic_ai(t_env *e)
{
	int				i;
	static int		ct = 0;
	double			dist;

	open_door(e);
	i = -1;
	ct = (ct == 40) ? 0 : ct + 1;
	while (++i < e->sprites_nbr && !(e->vict))
	{
		if (e->sprite_tab[i].life)
		{
			dist = sqrt((e->sprite_tab[i].pos_x - e->p.pos_x)
						* (e->sprite_tab[i].pos_x - e->p.pos_x)
						+ (e->sprite_tab[i].pos_y - e->p.pos_y)
						* (e->sprite_tab[i].pos_y - e->p.pos_y));
			if (ct == 40 && (dist < 10 || e->sprite_tab[i].life < 5))
				monsters_attack(e, i, dist);
			if ((dist < 10 || e->sprite_tab[i].life < 5) && dist > 1)
			{
				e->sprite_tab[i].plane_y = 1;
				move_sprite(e, i);
				e->sprite_tab[i].plane_y = 0;
			}
		}
	}
}

void		eat_cookies(t_env *e)
{
	int			i;
	double		dist;

	i = -1;
	while (++i < e->sprites_nbr)
	{
		if (e->sprite_tab[i].tex_id == 14
			|| e->sprite_tab[i].tex_id == 15)
		{
			dist = sqrt((e->sprite_tab[i].pos_x - e->p.pos_x)
						* (e->sprite_tab[i].pos_x - e->p.pos_x)
						+ (e->sprite_tab[i].pos_y - e->p.pos_y)
						* (e->sprite_tab[i].pos_y - e->p.pos_y));
			if (dist < 1 && (e->p.life < 5 || e->sprite_tab[i].tex_id == 15))
			{
				if (e->sprite_tab[i].tex_id == 14)
					e->p.life = e->p.life + 1;
				if (e->sprite_tab[i].tex_id == 15)
					e->key = e->key + 1;
				remove_one_obj_tab(e, i);
				i = i - 1;
			}
		}
	}
}
