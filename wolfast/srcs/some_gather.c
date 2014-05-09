/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_gather.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:23:47 by gmarais           #+#    #+#             */
/*   Updated: 2014/05/09 14:31:27 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** gather infos about the sprites in the file linked by path.
*/
int			gather_sprites(t_env *e, char *path)
{
	t_gather	var;

	if (set_sprite_num(e, path, &var))
		return (1);
	if ((var.fd = open(path, O_RDONLY)) < 0)
		return (1);
	var.y = -1;
	while (get_next_line(var.fd, &(var.line)) > 0 && var.line)
	{
		init_sprite_var(e, &var);
		while (var.line[var.x] && var.line[var.x] != ',')
		{
			if (var.line[var.x] == '.' && var.line[var.x + 1]
				&& !var.bol && (var.bol = 1))
				e->sprite_tab[var.y].pos_y = e->sprite_tab[var.y].pos_y
					+ (double)ft_atoi((char *)&(var.line[var.x + 1]))
					/ (double)ft_exp(10, numsize(var.line, var.x + 1));
			var.x++;
		}
		if (var.line[var.x] && var.line[var.x] == ',' && var.line[var.x + 1])
			e->sprite_tab[var.y].tex_id = ft_atoi((char *)&(var.line[var.x
																		+ 1]));
	}
	close(var.fd);
	return (0);
}

/*
** loading basic textures
*/
int			text_load(t_env *e, t_tex *image, char *file)
{
	int		w;
	int		h;

	w = TEX_WIDTH;
	h = TEX_HEIGHT;
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp,
									&image->sizeline, &image->endian);
	return (0);
}

/*
** loading the sky texture
*/
int			load_skybox(t_env *e, t_tex *image, char *file)
{
	int		w;
	int		h;

	w = SKY_WIDTH;
	h = SKY_HEIGHT;
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp,
									&image->sizeline, &image->endian);
	return (0);
}

/*
** loading the end_screen textures
*/
int			load_end_screens(t_env *e, t_tex *image, char *file)
{
	int		w;
	int		h;

	w = 320;
	h = 64;
	if (!(image->img = mlx_xpm_file_to_image(e->mlx, file, &w, &h)))
		return (-1);
	image->data = mlx_get_data_addr(image->img, &image->bpp,
									&image->sizeline, &image->endian);
	return (0);
}

/*
** loading images
*/
int			text_loader(t_env *e)
{
	text_load(e, &e->tex_tab[0], "../xpm_texts/trees2.xpm");
	text_load(e, &e->tex_tab[1], "../xpm_texts/trees1.xpm");
	text_load(e, &e->tex_tab[2], "../xpm_texts/grock.xpm");
	text_load(e, &e->tex_tab[3], "../xpm_texts/plank.xpm");
	text_load(e, &e->tex_tab[4], "../xpm_texts/housedoor5.xpm");
	text_load(e, &e->tex_tab[5], "../xpm_texts/housewall5.xpm");
	text_load(e, &e->tex_tab[6], "../xpm_texts/housewin5.xpm");
	text_load(e, &e->tex_tab[7], "../xpm_texts/monstblok0.xpm");
	text_load(e, &e->tex_tab[8], "../xpm_texts/monstblok.xpm");
	text_load(e, &e->tex_tab[9], "../xpm_texts/grass.xpm");
	text_load(e, &e->tex_tab[10], "../xpm_texts/monster0.xpm");
	text_load(e, &e->tex_tab[11], "../xpm_texts/monster0a.xpm");
	text_load(e, &e->tex_tab[12], "../xpm_texts/Monstre0d.xpm");
	text_load(e, &e->tex_tab[13], "../xpm_texts/projectile0.xpm");
	load_skybox(e, &e->skybox, "../xpm_texts/skybox.xpm");
	if (!e->tex_tab[0].img || !e->tex_tab[1].img
		|| !e->tex_tab[2].img || !e->tex_tab[3].img
		|| !e->tex_tab[4].img || !e->tex_tab[5].img
		|| !e->tex_tab[6].img || !e->tex_tab[7].img
		|| !e->tex_tab[8].img || !e->tex_tab[9].img
		|| !e->tex_tab[10].img || !e->tex_tab[11].img
		|| !e->tex_tab[12].img || !e->tex_tab[13].img
		|| !e->skybox.img)
		return (-1);
	return (0);
}
