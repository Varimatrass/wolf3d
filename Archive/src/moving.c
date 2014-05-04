/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 12:26:44 by tbalea            #+#    #+#             */
/*   Updated: 2014/01/17 21:07:57 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "tab.h"

int		read_key(int key_push, void *param)
{
	t_struct	*all;
	t_size		siz;
	t_touch		key_search;

	all = (t_struct *)param;
	key_search = touch();
	siz = size_win();
	if (key_push == key_search.esc)
		exit(0);
	else
		all->wol = read_key_wolf(key_push, all->wol, siz, all->wal);
	draw(all->wol, all->wal, all->win, siz);
	return (1);
}

t_wolf		read_key_wolf(int key_push, t_wolf wol, t_size siz, t_wall wal)
{
	t_touch	key_search;
	int		nya;

	nya = 8;
	key_search = touch();
	if (key_push == key_search.w)
		wol = move(wol, nya, wal);
	else if (key_push == key_search.s)
	{
		nya = nya * -1;
		wol = move(wol, nya, wal);
	}
	else if (key_push == key_search.a)
		wol = turn(wol, nya, siz);
	else if (key_push == key_search.d)
	{
		nya = nya * -1;
		wol = turn(wol, nya, siz);
	}
	return (wol);
}

t_wolf	turn(t_wolf wol, int nya, t_size siz)
{
	t_max	max;

	max = max_wall(siz);
	wol.pi = wol.pi - ((nya * 3.1415926) / (3 * max.max));
	if (wol.pi > (2 * 3.1415926) || wol.pi < (-2 * 3.1415926))
		 wol.pi = 0;
	return (wol);
}

t_wolf	move(t_wolf wol, int nya, t_wall wal)
{
	int		x;
	int		y;

	x = wol.posx + (nya * cos(wol.pi));
	y = wol.posy + (nya * sin(wol.pi));
	if (x < 0 || y < 0)
		return (wol);
	if (wal.lab[wol.posy / 64][x / 64] == '0')
	{
		wol.posx = x;
		if (wal.lab[y / 64][x / 64] == '0')
			wol.posy = y;
	}
	else if (wal.lab[y / 64][wol.posx / 64] == '0')
		wol.posy = y;
	return (wol);
}

t_wolf	where_wolf(t_wall wal)
{
	t_wolf	wol;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (wal.lab[y][x] != 48 && wal.lab[y][x] != '\0')
	{
		x = 0;
		while (wal.lab[y][x] != 48 && wal.lab[y][x] != '\0')
			x++;
		if (wal.lab[y][x] == '\0')
			x = 0;
		y++;
	}
	wol.posx = x * 64;
	wol.posy = y * 64;
	wol.pi = 0;
	return (wol);
}
