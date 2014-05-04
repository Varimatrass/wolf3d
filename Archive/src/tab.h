/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalea <tbalea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 14:23:23 by tbalea            #+#    #+#             */
/*   Updated: 2014/01/19 01:55:09 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAB_H
# define TAB_H

typedef struct	s_wolf
{
	int			posx;
	int			posy;
	float		pi;
}				t_wolf;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
}				t_win;

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_wall
{
	char	**lab;
	int		*rang;
	int		*clor;
}				t_wall;

typedef struct	s_color
{
	int		sky;
	int		walw;
	int		wals;
	int		wale;
	int		waln;
	int		earth;
}				t_color;

typedef struct	s_max
{
	int		max;
	int		mxwl;
}				t_max;

typedef struct	s_touch
{
	int		esc;
	int		w;
	int		a;
	int		d;
	int		s;
}				t_touch;

typedef struct	s_struct
{
	t_wolf		wol;
	t_wall		wal;
	t_win		win;
}				t_struct;

typedef struct	s_ray
{
	int			crash;
	float		ray;
}				t_ray;

int		which_color(int sens);
int		wall_color(t_size ray, t_wall wal, float wol, float wra);
char	**read_map(char **brick);
void	draw(t_wolf Wolf, t_wall Wall, t_win Win, t_size size);
void	draw_wall(t_win w, t_size size, t_wall wall);
t_wall	ray_casting(t_wolf Wolf, t_wall Brick, t_max max, t_size size);
void	draw_earthnsky(t_win win, t_size size);
t_win	new_screen(void);
t_wolf	turn(t_wolf wolf, int nya, t_size size);
t_wolf	move(t_wolf wolf, int nya, t_wall wall);
t_wolf	where_wolf(t_wall wall);
t_wolf	read_key_wolf(int key_push, t_wolf wolf, t_size size, t_wall wall);
int		read_key(int key_push, void *param);
t_color	color_env(void);
t_size	size_win(void);
char	*name_win(void);
t_max	max_wall(t_size size);
t_touch	touch(void);

#endif /* TAB_H */
