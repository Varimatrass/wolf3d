/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 18:59:55 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/18 19:30:05 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			interface_loader(t_env *e)
{
	text_load(e, &e->gun_tex[0], "./xpm_texts/pistolet.xpm");
	text_load(e, &e->gun_tex[1], "./xpm_texts/pistolet0.xpm");
	text_load(e, &e->tex_tab[14], "./xpm_texts/cookies.xpm");
	text_load(e, &e->tex_tab[15], "./xpm_texts/key.xpm");
	text_load(e, &e->tex_tab[16], "./xpm_texts/housedoor0.xpm");
	text_load(e, &e->tex_tab[17], "./xpm_texts/housewin0.xpm");
	text_load(e, &e->tex_tab[18], "./xpm_texts/housewall0.xpm");
	text_load(e, &e->tex_tab[19], "./xpm_texts/porte.xpm");
	load_end_screens(e, &e->end_screen[0], "./xpm_texts/youdied.xpm");
	load_end_screens(e, &e->end_screen[1], "./xpm_texts/youwon.xpm");
	if (!e->gun_tex[0].img || !e->gun_tex[1].img
		|| !e->tex_tab[14].img || !e->tex_tab[15].img
		|| !e->tex_tab[16].img || !e->tex_tab[17].img
		|| !e->tex_tab[18].img || !e->end_screen[0].img
		|| !e->end_screen[1].img || !e->tex_tab[19].img)
		return (-1);
	return (0);
}

/*
** Print shape of world in stdout if needed for debug
*/
void		print_world(t_env *e)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (e->world[i])
	{
		j = 0;
		while (e->world[i][j])
		{
			ft_putstr(e->world[i][j]);
			if (e->world[i][j + 1])
				ft_putchar(' ');
			else
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}

/*
** initializing player's coordinates and variables
*/
void		player_init(t_env *e)
{
	e->p.life = 5;
	e->p.pos_x = 22.0;
	e->p.pos_y = 11.5;
	e->p.dir_x = -1.0;
	e->p.dir_y = 0.0;
	e->p.plane_x = 0.0;
	e->p.plane_y = 0.66;
	e->move.fwd = 0;
	e->move.bwd = 0;
	e->move.rlft = 0;
	e->move.rrgt = 0;
	e->move.slft = 0;
	e->move.srgt = 0;
	e->shooting = 0;
	e->door = 0;
	e->op = 0;
	e->key = 0;
	e->vict = 0;
}

void		patch_sprite_tab(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->sprites_nbr)
	{
		if (e->sprite_tab[i].tex_id > 12)
		{
			e->sprite_tab[i].life = 0;
			e->sprite_tab[i].plane_x = 0;
			e->sprite_tab[i].plane_y = 1;
		}
	}
}

int			main()
{
	t_env	e;

	if (create_world(&e, "world.w3d") || gather_sprites(&e, "sprites.w3d"))
		return (1);
	patch_sprite_tab(&e);
	player_init(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Pink them all");
	e.im_tmp = mlx_new_image(e.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	e.data = mlx_get_data_addr(e.im_tmp, &(e.bpp), &(e.sizeline), &(e.endian));
	if (text_loader(&e) || interface_loader(&e))
	{
		ft_putendl_fd("Error : could not properly load textures.", 2);
		return (-1);
	}
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, draw, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, key_hook, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, key_hook_r, &e);
	mlx_loop(e.mlx);
	return (0);
}
