/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 01:23:37 by opettex-          #+#    #+#             */
/*   Updated: 2016/04/09 03:04:05 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				move_tab(int keycode, t_env *e)
{
	if (keycode == UP)
		e->vert -= 20;
	else if (keycode == DOWN)
		e->vert += 20;
	else if (keycode == LEFT)
		e->horyz -= 20;
	else if (keycode == RIGHT)
		e->horyz += 20;
	new_image(e);
	print_map(e);
}

void				color_max_z(t_env *e)
{
	int				x;
	int				y;

	y = -1;
	while (++y < e->max_line)
	{
		x = -1;
		while (++x < e->max_char)
		{
			if (e->tab[y][x] < e->min_z)
				e->min_z = e->tab[y][x];
			else if (e->tab[y][x] > e->max_z)
				e->max_z = e->tab[y][x];
		}
	}
	e->distance = e->max_z - e->min_z;
}

static void			color_z2(t_env *e, double z, int r)
{
	if (z >= (e->min_z + r * 7) && z <= (e->min_z + r * 8))
		e->color = GOLD;
	else if (z >= (e->min_z + r * 8) && z <= (e->min_z + r * 9))
		e->color = PERU;
	else if (z >= (e->min_z + r * 9) && z <= (e->min_z + r * 10))
		e->color = ORANGE;
	else if (z >= (e->min_z + r * 10) && z <= (e->min_z + r * 11))
		e->color = ORANGERED;
	else if (z >= (e->min_z + r * 11) && z <= (e->min_z + r * 12))
		e->color = RED;
	else if (z >= (e->min_z + r * 12) && z <= (e->min_z + r * 13))
		e->color = FIREBRICK;
	else if (z >= (e->min_z + r * 13) && z <= (e->min_z + r * 14))
		e->color = MAROON;
	else if (z >= (e->min_z + r * 14) && z <= (e->min_z + r * 15))
		e->color = SIENNA;
	else if (z >= (e->min_z + r * 15) && z <= (e->max_z))
		e->color = SADDLEBROWN;
}

void				color_z(t_env *e, double z)
{
	int				r;

	r = e->distance / 16;
	if (z >= e->min_z && z < (e->min_z + r))
		e->color = TEAL;
	else if (z >= e->min_z + r && z < (e->min_z + r * 2))
		e->color = LIGHTSEAGREEN;
	else if (z >= (e->min_z + r * 2) && z < (e->min_z + r * 3))
		e->color = TURQUOISE;
	else if (z >= (e->min_z + r * 3) && z < (e->min_z + r * 4))
		e->color = WHITE;
	else if (z >= (e->min_z + r * 4) && z < (e->min_z + r * 5))
		e->color = ACQUAMARINE;
	else if (z >= (e->min_z + r * 5) && z < (e->min_z + r * 6))
		e->color = PALEGREEN;
	else if (z >= (e->min_z + r * 6) && z <= (e->min_z + r * 7))
		e->color = YELLOWGREEN;
	color_z2(e, z, r);
}

void				key_zoom(int keycode, t_env *e)
{
	if (keycode == PLUS || keycode == 24)
		e->zoom *= 1.5;
	if (keycode == MOINS || keycode == 27)
		e->zoom /= 1.5;
	new_image(e);
	print_map(e);
}
