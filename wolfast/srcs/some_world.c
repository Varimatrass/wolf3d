/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 18:19:51 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/18 19:06:09 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	world_assign(t_env *e, t_cnt *c, char *line)
{
	int		count;

	count = numsize(line, c->i);
	e->world[c->j][c->k] = ft_strsub(line, c->i , count);
	(c->k)++;
	c->i += count;
}

/*
** getting the infos from the file.
*/
int			world_init(t_env *e, char *path)
{
	int		fd;
	t_cnt	c;
	char	*line;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (1);
	c.j = -1;
	while (get_next_line(fd, &line) > 0 && line && (c.j++ || 42))
	{
		c.k = 0;
		if (line[(c.i = 0)] && (line [c.i] != ' '))
			world_assign(e, &c, line);
		while (line[c.i] && (line[c.i] == ' '))
		{
			if (line[++(c.i)] && (line [c.i] != ' '))
				world_assign(e, &c, line);
		}
		e->world[c.j][c.k] = NULL;
		free(line);
	}
	e->world[c.j] = NULL;
	close(fd);
	return (0);
}

/*
** create the shape of the world by reading the link given by path.
*/
int			create_world(t_env *e, char *path)
{
	size_t	max_x;
	size_t	max_y;
	int		error;

	max_x = 0;
	max_y = 0;
	error = get_world_size(&max_x, &max_y, path);
	if (error)
		return (1);
	e->map_width = max_x;
	e->map_height = max_y;
	max_y++;
	max_x++;
	error = world_alloc(e, max_x, max_y);
	if (error)
		return (1);
	error = world_init(e, path);
	if (error)
		return (1);
	return (0);
}

int			set_sprite_num(t_env *e, char *path, t_gather *var)
{
	var->y = 0;
	if ((var->fd = open(path, O_RDONLY)) < 0)
		return (1);
	while (get_next_line(var->fd, &(var->line)) > 0 && var->line)
		var->y++;
	close(var->fd);
	e->sprite_tab = (t_obj *)malloc(sizeof(t_obj) * var->y);
	e->sprites_nbr = var->y;
	return (0);
}

void		init_sprite_var(t_env *e, t_gather *var)
{
	var->y++;
	e->sprite_tab[var->y].pos_y = 0.0;
	e->sprite_tab[var->y].plane_y = 0;
	e->sprite_tab[var->y].life = 5;
	e->sprite_tab[var->y].plane_x = var->y % 4;
	e->sprite_tab[var->y].tex_id = 0.0;
	e->sprite_tab[var->y].pos_x = (double)ft_atoi(var->line);
	var->x = 0;
	var->bol = 0;
	while (var->line[var->x] && var->line[var->x] != ',')
	{
		if (var->line[var->x] == '.' && var->line[var->x + 1]
			&& !var->bol && (var->bol = 1))
			e->sprite_tab[var->y].pos_x = e->sprite_tab[var->y].pos_x
				+ (double)(ft_atoi((char *)&(var->line[var->x + 1])))
				/ (ft_exp(10, numsize(var->line, var->x + 1)));
		var->x++;
	}
	if (var->line[var->x] && var->line[var->x] == ',' && var->line[var->x + 1])
		e->sprite_tab[var->y].pos_y = ft_atoi((char *)&(var->line[++var->x]));
	var->bol = 0;
}
