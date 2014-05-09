/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 19:29:32 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/19 21:42:17 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		teleport_bis(t_env *e)
{
	if ((int)(e->p.pos_x) == 11
		&& (int)(e->p.pos_y) == 30)
	{
		e->p.pos_x = 25.5;
		e->p.pos_y = 12.5;
		e->p.dir_x = 1;
		e->p.dir_y = 0;
		e->p.plane_x = 0.0;
		e->p.plane_y = -0.66;
	}
	else if ((int)(e->p.pos_x) == 25
				&& (int)(e->p.pos_y) == 12)
	{
		e->p.pos_x = 11.5;
		e->p.pos_y = 30.5;
		e->p.dir_x = 0;
		e->p.dir_y = -1;
		e->p.plane_x = -0.66;
		e->p.plane_y = 0.00;
	}
	else
		teleport_bis_bis(e);
}

void		teleport_bis_bis(t_env *e)
{
	if ((int)(e->p.pos_x) == 15
		&& (int)(e->p.pos_y) == 27)
	{
		e->p.pos_x = 31.5;
		e->p.pos_y = 2.5;
		e->p.dir_x = 1;
		e->p.dir_y = 0;
		e->p.plane_x = 0.0;
		e->p.plane_y = -0.66;
	}
	else if ((int)(e->p.pos_x) == 31
				&& (int)(e->p.pos_y) == 2)
	{
		e->p.pos_x = 15.5;
		e->p.pos_y = (!colision_check(e, 15.5, 27.5)) ? 27.5 : 28.5;
		e->p.dir_x = 0;
		e->p.dir_y = 1;
		e->p.plane_x = 0.66;
		e->p.plane_y = 0.00;
	}
}
