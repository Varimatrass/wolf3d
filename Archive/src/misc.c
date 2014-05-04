/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 21:38:29 by tbalea            #+#    #+#             */
/*   Updated: 2014/01/18 23:07:09 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "tab.h"

char	**read_map(char **brick)
{
	int		y;
	int		x;

	y = 5;
	x = 28;
	brick = (char **)malloc(sizeof(char *) * y);
	while (y-- > 0)
		brick[y] = (char *)malloc(sizeof(char *) * x);
	brick[0] = "1111111111111111111111111111";
	brick[1] = "1010000100000100000000000001";
	brick[2] = "1010100111011100111011010001";
	brick[3] = "1000100000000000000000000001";
	brick[4] = "1111111111111111111111111111";
	return (brick);
}

int		which_color(int sens)
{
	t_color	color;

	color = color_env();
	if (sens == 0)
		return (color.wals);
	if (sens == 1)
		return (color.wale);
	if (sens == 2)
		return (color.walw);
	return (color.waln);
}

t_win	new_screen(void)
{
	t_win	win;
	t_size	siz;
	char	*nam;

	nam = name_win();
	siz = size_win();
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, siz.x, siz.y, nam);
	return (win);
}
