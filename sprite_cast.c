/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:54:55 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 16:55:28 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_sprite_tab(t_env *e)
{
	static int	ct = 0;
	int			i;

	ct++;
	i = -1;
	while (++i < e->sprites_nbr)
	{
		if (ct == 20 && e->sprite_tab[i].tex_id == 10)
			e->sprite_tab[i].tex_id = 11;
		else if (ct == 20 && e->sprite_tab[i].tex_id == 11)
			e->sprite_tab[i].tex_id = 10;
		e->sprite_tab[i].dist = ((e->p.pos_x - e->sprite_tab[i].pos_x)
						* (e->p.pos_x - e->sprite_tab[i].pos_x)
						+ (e->p.pos_y - e->sprite_tab[i].pos_y)
						* (e->p.pos_y - e->sprite_tab[i].pos_y));
	}
	if (ct >= 20)
		ct = 0;
}

void		set_trans_xy(t_env *e, t_spricast *va)
{
	double	rel_spt_x;
	double	rel_spt_y;
	double	inv_det;

	rel_spt_x = (e->sprite_tab[va->i]).pos_x - e->p.pos_x;
	rel_spt_y = (e->sprite_tab[va->i]).pos_y - e->p.pos_y;
	inv_det = 1.0 / (e->p.plane_x * e->p.dir_y
						- e->p.plane_y * e->p.dir_x);
	va->trans_x = inv_det * (e->p.dir_y * rel_spt_x
								- e->p.dir_x * rel_spt_y);
	va->trans_y = inv_det * (-(e->p.plane_y) * rel_spt_x
								+ e->p.plane_x * rel_spt_y);
}

void		set_sprite_draw_strt_nd(t_spricast *va, t_trac_data *d, t_env *e)
{
	int		z_mv;

	z_mv = (e->sprite_tab[va->i].tex_id >= 14) ? 20 : 0;
	va->sprite_screen_x = (int)((SCREEN_WIDTH / 2)
								* (1 + va->trans_x / va->trans_y));
	va->sprite_height = ft_abs((int)(SCREEN_HEIGHT / va->trans_y));
	if (e->sprite_tab[va->i].tex_id == 14)
		va->sprite_height /= 2;
	va->draw_start_y = SCREEN_HEIGHT / 2 + z_mv - va->sprite_height / 2;
	if (va->draw_start_y < 0)
		va->draw_start_y = 0;
	va->draw_end_y = SCREEN_HEIGHT / 2 + z_mv + va->sprite_height / 2;
	if (va->draw_end_y >= SCREEN_HEIGHT)
		va->draw_end_y = SCREEN_HEIGHT - 1;
	va->sprite_width = ft_abs((int)(SCREEN_HEIGHT / (va->trans_y)));
	d->draw_start = va->sprite_screen_x - va->sprite_width / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = va->sprite_screen_x + va->sprite_width / 2;
	if (d->draw_end >= SCREEN_WIDTH)
		d->draw_end = SCREEN_WIDTH - 1;
}

void		pimp_my_sprite(t_env *e, t_trac_data *d, t_spricast *va)
{
	int		z_mv;
	int		dec;
	int		id;

	z_mv = (e->sprite_tab[va->i].tex_id >= 14) ? 20 : 0;
	id = (e->sprite_tab[va->i]).tex_id;
	dec = (va->y - z_mv) * 256 - SCREEN_HEIGHT * 128 + va->sprite_height * 128;
	d->tex_y = ((dec * TEX_HEIGHT) / va->sprite_height) / 256;
	va->col.b = ((e->tex_tab[id]).data)[(d->tex_y
											* (e->tex_tab[id]).sizeline
											+ ((e->tex_tab[id]).bpp / 8)
											* d->tex_x)];
	va->col.g = ((e->tex_tab[id]).data)[(d->tex_y
											* (e->tex_tab[id]).sizeline
											+ ((e->tex_tab[id]).bpp / 8)
											* d->tex_x) + 1];
	va->col.r = ((e->tex_tab[id]).data)[(d->tex_y
											* (e->tex_tab[id]).sizeline
											+ ((e->tex_tab[id]).bpp / 8)
											* d->tex_x) + 2];
}

void		sprite_in_img(t_env *e, t_trac_data *d, t_spricast *va)
{
	if (!(e->sprite_tab[va->i]).plane_x)
	{
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8)] = va->col.b;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 1] = va->col.g;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 2] = va->col.r;
	}
	else if ((e->sprite_tab[va->i]).plane_x == 1)
	{
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8)] = va->col.r;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 1] = va->col.b;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 2] = va->col.g;
	}
	else if ((e->sprite_tab[va->i]).plane_x == 2)
	{
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8)] = va->col.b;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 1] = va->col.r;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 2] = va->col.g;
	}
	else
	{
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8)] = va->col.r;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 1] = va->col.g;
		e->data[va->y * e->sizeline + d->x * (e->bpp / 8) + 2] = va->col.b;
	}
}
