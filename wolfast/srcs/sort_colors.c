/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:54:04 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 13:54:07 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_door_color(t_env *e, t_trac_data *d, int i, t_colors *col)
{
	int				dec;

	if (d->dtex_x < 0)
	{
		col->b = 0;
		col->g = 0;
		col->r = 0;
		return ;
	}
	dec = i * 256 - SCREEN_HEIGHT * 128 + d->dline_height * 128;
	d->tex_y = ((dec * TEX_HEIGHT) / d->dline_height) / 256;
	col->b =  e->tex_tab[19].data[(d->tex_y
											* e->tex_tab[19].sizeline
											+ e->tex_tab[19].bpp / 8
											* d->dtex_x)];
	col->g =  e->tex_tab[19].data[(d->tex_y
											* e->tex_tab[19].sizeline
											+ e->tex_tab[19].bpp / 8
											* d->dtex_x) + 1];
	col->r =  e->tex_tab[19].data[(d->tex_y
											* e->tex_tab[19].sizeline
											+ e->tex_tab[19].bpp / 8
											* d->dtex_x) + 2];
}

void		get_pixel_color(t_env *e, t_trac_data *d, int i, t_colors *col)
{
	int				dec;

		dec = i * 256 - SCREEN_HEIGHT * 128 + d->line_height * 128;
		d->tex_y = ((dec * TEX_HEIGHT) / d->line_height) / 256;
		col->b =  e->tex_tab[d->tex_id].data[(d->tex_y
												* e->tex_tab[d->tex_id].sizeline
												+ e->tex_tab[d->tex_id].bpp / 8
												* d->tex_x)];
		col->g =  e->tex_tab[d->tex_id].data[(d->tex_y
												* e->tex_tab[d->tex_id].sizeline
												+ e->tex_tab[d->tex_id].bpp / 8
												* d->tex_x) + 1];
		col->r =  e->tex_tab[d->tex_id].data[(d->tex_y
												* e->tex_tab[d->tex_id].sizeline
												+ e->tex_tab[d->tex_id].bpp / 8
												* d->tex_x) + 2];
}

void		apply_shadow(t_trac_data *d, t_obj *ray, t_colors *col)
{
	if (d->side == 1 || (d->side == 0 && ray->dir_x >= 0))
	{
		if (d->side == 0)
		{
			col->b = (int)(col->b /1.5);
			col->g = (int)(col->g /1.5);
			col->r = (int)(col->r /1.5);
		}
		else if (d->side == 1 && ray->dir_y >= 0)
		{
			col->b = (int)(col->b /1.10);
			col->g = (int)(col->g /1.10);
			col->r = (int)(col->r /1.10);
		}
		else
		{
			col->b = (int)(col->b /1.25);
			col->g = (int)(col->g /1.25);
			col->r = (int)(col->r /1.25);
		}
	}
}

void		ft_swap_objtab(t_env *e, int *i, int *j)
{
	t_obj	tmpo;

	tmpo = e->sprite_tab[*i];
	e->sprite_tab[*i] = e->sprite_tab[*j];
	e->sprite_tab[*j] = tmpo;
}

void		sort_tab(t_env *e)
{
	int gap;
	int swapped;
	int i;
	int j;

	gap = e->sprites_nbr;
	swapped = 1;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		gap = (gap == 9 || gap == 10) ? 11 : gap;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		i = -1;
		while (++i < e->sprites_nbr - gap)
		{
			j = i + gap;
			if (e->sprite_tab[i].dist < e->sprite_tab[j].dist)
			{
				ft_swap_objtab(e, &i, &j);
				swapped = 1;
			}
		}
	}
}
