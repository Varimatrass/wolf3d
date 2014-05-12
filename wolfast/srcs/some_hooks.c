/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:53:05 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 13:53:10 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_hook(int keycode, t_env *e)
{
	if (e->p.life)
	{
		if (keycode == 32)
			shoot(e);
		if (keycode == 101)
			apply_teleport(e);
		if (keycode == 65362 || keycode == 122 || keycode == 119)
			e->move.fwd = 1;
		if (keycode == 65364 || keycode == 115)
			e->move.bwd = 1;
		if (keycode == 65361)
			e->move.rlft = 1;
		if (keycode == 65363)
			e->move.rrgt = 1;
		if (keycode == 100)
			e->move.slft = 1;
		if (keycode == 97 || keycode == 113)
			e->move.srgt = 1;
	}
	if (keycode == 65307 && e)
		exit(0);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int			numsize(char *str, int i)
{
	int		count;

	count = 0;
	while (str[i] && (str[i] != ' ') && (str[i] != ','))
	{
		count++;
		i++;
	}
	return (count);
}

/*
** getting the size of the tab to allocate with dynamic memory.
*/
int			get_world_size(size_t *max_x, size_t *max_y, char *path)
{
	int		fd;
	int		i;
	size_t	maxx;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (1);
	while (get_next_line(fd, &path) > 0 && path)
	{
		i = 0;
		maxx = 0;
		if (path[i] && (path[i] != ' ') && ++maxx)
			i += numsize(path, i);
		while (path[i] && (path[i] == ' '))
		{
			i++;
			if (path[i] && (path[i] != ' ') && ++maxx)
				i += numsize(path, i);
		}
		free(path);
		*max_x = (maxx > *max_x) ? maxx : *max_x;
		(*max_y)++;
	}
	while (0 && (*max_x && *max_y));
	close(fd);
	return (0);
}

/*
** allocating memory...
*/
int			world_alloc(t_env *e, int max_x, int max_y)
{
	int		i;

	e->world = (char ***)malloc(max_y * sizeof(char **));
	if (!e->world)
		return (1);
	i = 0;
	while (i < max_y)
	{
		e->world[i] = (char **)malloc(sizeof(char *) * (max_x));
		i++;
	}
	e->world[i] = (char **)malloc(sizeof(char *));
	e->world[i] = NULL;
	return (0);
}
