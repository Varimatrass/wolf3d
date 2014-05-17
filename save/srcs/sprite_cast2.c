/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:55:05 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 16:56:11 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		print_my_sprite(t_env *e, t_trac_data *d, t_spricast *va)
{
	d->tex_x = (int)(256 * (d->x - (va->sprite_screen_x - va->sprite_width / 2))
						* TEX_WIDTH / va->sprite_width) / 256;
	if (va->trans_y > 0 && d->x > 0 && d->x < SCREEN_WIDTH
		&& va->trans_y < d->z_buffer[d->x])
	{
		va->y = va->draw_start_y - 1;
		while (++(va->y) < va->draw_end_y)
		{
			pimp_my_sprite(e, d, va);
			if (va->col.b || va->col.g || va->col.r)
				sprite_in_img(e, d, va);
		}
	}
}

void		get_gun_color(t_env	*e, int i, int j, t_colors *col)
{
	int		id;

	id = (e->shooting) ? 1 : 0;
	col->b = ((e->gun_tex)[id].data)[(j * (e->gun_tex)[id].sizeline
										+ ((e->gun_tex)[id].bpp / 8) * i)];
	col->g = ((e->gun_tex)[id].data)[(j * (e->gun_tex)[id].sizeline
										+ ((e->gun_tex)[id].bpp / 8) * i) + 1];
	col->r = ((e->gun_tex)[id].data)[(j * (e->gun_tex)[id].sizeline
										+ ((e->gun_tex)[id].bpp / 8) * i) + 2];
}

void		put_gun(t_env *e, int i, int j, t_colors *col)
{
	e->data[i * e->sizeline + j * (e->bpp / 8)] = col->b;
	e->data[i * e->sizeline + j * (e->bpp / 8) + 1] = col->g;
	e->data[i * e->sizeline + j * (e->bpp / 8) + 2] = col->r;
}

void		gun_to_img(t_env *e)
{
	int			i;
	int			j;
	t_colors	col;

	j = SCREEN_WIDTH / 2 - SCREEN_WIDTH / 10;
	while (++j < SCREEN_WIDTH / 2 + SCREEN_WIDTH / 10)
	{
		i = SCREEN_HEIGHT - SCREEN_HEIGHT / 4;
		while (++i < SCREEN_HEIGHT)
		{
			get_gun_color(e, (j - (SCREEN_WIDTH / 2.0 - SCREEN_WIDTH / 10.0))
							/ ((SCREEN_WIDTH / 2.0 + SCREEN_WIDTH / 10.0)
							- (SCREEN_WIDTH / 2.0 - SCREEN_WIDTH / 10.0))
							* TEX_WIDTH, (i - (SCREEN_HEIGHT - SCREEN_HEIGHT
												/ 4.0))
							/ (SCREEN_HEIGHT - (SCREEN_HEIGHT - SCREEN_HEIGHT
												/ 4.0))
							* TEX_HEIGHT, &col);
			if (col.b || col.g || col.r)
				put_gun(e, i, j, &col);
		}
	}
}

int			colision_check(t_env *e, double x, double y)
{
	int		i;

	if (ft_atoi(e->world[(int)x][(int)y])
		|| (e->world[(int)x][(int)y][0] == 'D' && e->door != 64))
		return (-1);
	i = -1;
	while (++i < e->sprites_nbr)
	{
		if (e->sprite_tab[i].life
			&& e->sprite_tab[i].plane_y != 1
			&& sqrt((e->sprite_tab[i].pos_x - x)
					* (e->sprite_tab[i].pos_x - x)
					+ (e->sprite_tab[i].pos_y - y)
					* (e->sprite_tab[i].pos_y - y))
			< 0.5)
			return (i + 1);
	}
	return (0);
}
