/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:38:13 by tbalea            #+#    #+#             */
/*   Updated: 2014/01/18 21:37:48 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "tab.h"

int		main(void)
{
	t_struct	all;
	t_size		siz;

	siz = size_win();
	all.wal.lab = read_map(all.wal.lab);
	all.win = new_screen();
	all.wol = where_wolf(all.wal);
	draw(all.wol, all.wal, all.win, siz);
	mlx_do_key_autorepeaton(all.win.mlx);
	mlx_hook(all.win.win, 2, (1l << 0), read_key, &all);
	mlx_loop(all.win.mlx);
	return (1);
}
