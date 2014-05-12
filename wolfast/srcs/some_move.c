/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:53:25 by mde-jesu          #+#    #+#             */
/*   Updated: 2014/05/12 16:48:09 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		apply_strafing(t_env *e)
{
	if (e->move.slft != e->move.srgt)
	{
		if (e->move.slft == 1)
		{
			if (!colision_check(e, e->p.pos_x + e->p.plane_x * 0.2, e->p.pos_y))
				e->p.pos_x += e->p.plane_x * 0.1;
			if (!colision_check(e, e->p.pos_x, e->p.pos_y + e->p.plane_y * 0.2))
				e->p.pos_y += e->p.plane_y * 0.1;
		}
		if (e->move.srgt == 1)
		{
			if (!colision_check(e, e->p.pos_x - e->p.plane_x * 0.2, e->p.pos_y))
				e->p.pos_x -= e->p.plane_x * 0.1;
			if (!colision_check(e, e->p.pos_x, e->p.pos_y - e->p.plane_y * 0.2))
				e->p.pos_y -= e->p.plane_y * 0.1;
		}
	}
}

void		apply_rot(t_env *e)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = e->p.dir_x;
	old_plane_x = e->p.plane_x;
	if (e->move.rrgt != e->move.rlft)
	{
		if (e->move.rrgt == 1)
		{
			e->p.dir_x = e->p.dir_x * cos(-0.07) - e->p.dir_y * sin(-0.07);
			e->p.dir_y = old_dir_x * sin(-0.07) + e->p.dir_y * cos(-0.07);
			e->p.plane_x = e->p.plane_x
				* cos(-0.07) - e->p.plane_y * sin(-0.07);
			e->p.plane_y = old_plane_x * sin(-0.07) + e->p.plane_y * cos(-0.07);
		}
		if (e->move.rlft == 1)
		{
			e->p.dir_x = e->p.dir_x * cos(0.07) - e->p.dir_y * sin(0.07);
			e->p.dir_y = old_dir_x * sin(0.07) + e->p.dir_y * cos(0.07);
			e->p.plane_x = e->p.plane_x * cos(0.07) - e->p.plane_y * sin(0.07);
			e->p.plane_y = old_plane_x * sin(0.07) + e->p.plane_y * cos(0.07);
		}
	}
}

void		apply_move(t_env *e)
{
	if (e->move.fwd != e->move.bwd)
	{
		if (e->move.fwd == 1)
		{
			if (!colision_check(e, e->p.pos_x + e->p.dir_x * 0.2, e->p.pos_y))
				e->p.pos_x += e->p.dir_x * 0.1;
			if (!colision_check(e, e->p.pos_x, e->p.pos_y + e->p.dir_y * 0.2))
				e->p.pos_y += e->p.dir_y * 0.1;
		}
		if (e->move.bwd == 1)
		{
			if (!colision_check(e, e->p.pos_x - e->p.dir_x * 0.2, e->p.pos_y))
				e->p.pos_x -= e->p.dir_x * 0.1;
			if (!colision_check(e, e->p.pos_x, e->p.pos_y - e->p.dir_y * 0.2))
				e->p.pos_y -= e->p.dir_y * 0.1;
		}
	}
}

void		apply_teleport(t_env *e)
{
	if ((int)(e->p.pos_x) == 11
		&& (int)(e->p.pos_y) == 22)
		e->op = (e->op == 1) ? -1 : 1;
	else if ((int)(e->p.pos_x) == 13
				&& (int)(e->p.pos_y) == 5)
	{
		e->p.pos_x = 25.5;
		e->p.pos_y = 5.5;
		e->p.dir_x = 1;
		e->p.dir_y = 0;
		e->p.plane_x = 0.0;
		e->p.plane_y = -0.66;
	}
	else if ((int)(e->p.pos_x) == 25
				&& (int)(e->p.pos_y) == 5)
	{
		e->p.pos_x = 13.5;
		e->p.pos_y = 5.5;
		e->p.dir_x = 0;
		e->p.dir_y = 1;
		e->p.plane_x = 0.66;
		e->p.plane_y = 0.00;
	}
	else
		teleport_bis(e);
}

void		shoot(t_env *e)
{
	e->shooting = 1;
}
