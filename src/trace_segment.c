/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_segment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:32:49 by opettex-          #+#    #+#             */
/*   Updated: 2016/04/06 12:32:41 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"
#include <math.h>

void		trace_2(t_env *e, int xinc, int yinc, int color)
{
	e->cumul = e->dx / 2;
	e->cmp = 0;
	while (++e->cmp <= e->dx)
	{
		e->x += xinc;
		e->cumul += e->dy;
		if (e->cumul >= e->dx)
		{
			e->cumul -= e->dx;
			e->y += yinc;
		}
		put_pixel_to_img(e, e->x, e->y, color);
	}
}

void		trace_3(t_env *e, int xinc, int yinc, int color)
{
	e->cumul = e->dy / 2;
	e->cmp = 0;
	while (++e->cmp <= e->dy)
	{
		e->y += yinc;
		e->cumul += e->dx;
		if (e->cumul >= e->dy)
		{
			e->cumul -= e->dy;
			e->x += xinc;
		}
		put_pixel_to_img(e, e->x, e->y, color);
	}
}

void		trace_line(t_env *e, int color)
{
	int		xinc;
	int		yinc;

	e->x = e->sx;
	e->y = e->sy;
	e->dx = e->ex - e->sx;
	e->dy = e->ey - e->sy;
	xinc = (e->dx > 0) ? 1 : -1;
	yinc = (e->dy > 0) ? 1 : -1;
	e->dx = abs(e->dx);
	e->dy = abs(e->dy);
	put_pixel_to_img(e, e->x, e->y, color);
	if (e->dx > e->dy)
		trace_2(e, xinc, yinc, color);
	else
		trace_3(e, xinc, yinc, color);
}

static void	draw_iso2(t_env *e)
{
	if (e->xd + 1 < e->max_char)
	{
		e->sx = ((e->xd - e->yd) * e->zoom) + e->horyz;
		e->sy = (e->yd * e->zoom) + e->vert - (e->tab[e->yd][e->xd] * e->zvar);
		e->ex = (e->xd - e->yd + 1) * e->zoom + e->horyz;
		e->ey = (e->yd * e->zoom) + e->vert
			- (e->tab[e->yd][e->xd + 1] * e->zvar);
		if (e->tab[e->yd][e->xd] < e->tab[e->yd][e->xd + 1])
			trace_line(e, e->tab_color[e->yd][e->xd + 1]);
		else
			trace_line(e, e->tab_color[e->yd][e->xd]);
	}
	if (e->yd + 1 < e->max_line)
	{
		e->sx = ((e->xd - e->yd) * e->zoom) + e->horyz;
		e->sy = (e->yd * e->zoom) + e->vert - (e->tab[e->yd][e->xd] * e->zvar);
		e->ex = (e->xd - e->yd - 1) * e->zoom + e->horyz;
		e->ey = (e->yd + 1) * e->zoom + e->vert
			- (e->tab[e->yd + 1][e->xd] * e->zvar);
		if (e->tab[e->yd][e->xd] < e->tab[e->yd + 1][e->xd])
			trace_line(e, e->tab_color[e->yd + 1][e->xd]);
		else
			trace_line(e, e->tab_color[e->yd][e->xd]);
	}
}

void		draw_iso(t_env *e)
{
	e->yd = -1;
	while (++e->yd < e->max_line)
	{
		e->xd = -1;
		while (++e->xd < e->max_char)
			draw_iso2(e);
	}
}
