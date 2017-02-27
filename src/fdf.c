/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:09:38 by opettex-          #+#    #+#             */
/*   Updated: 2016/05/04 13:02:34 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		close_image(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}

void		new_image(t_env *e)
{
	if (!(e->img = mlx_new_image(e->mlx, IMG_X, IMG_Y)))
	{
		ft_putendl("Error init img");
		exit(1);
	}
	if (!(e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->end)))
	{
		ft_putendl("Error init data");
		exit(1);
	}
	e->bpp /= 8;
}

void		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	if (!(e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "42")))
	{
		ft_putendl("Error init window");
		exit(1);
	}
	new_image(e);
}

void		put_pixel_to_img(t_env *e, int x, int y, int color)
{
	if (x < WIN_X && y < WIN_Y && x >= 0 && y >= 0)
		*(unsigned int *)(e->data + e->bpp * x + e->sl * y) = color;
}

void		print_map(t_env *e)
{
	draw_iso(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
