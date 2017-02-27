/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:18:13 by opettex-          #+#    #+#             */
/*   Updated: 2016/07/01 17:14:52 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_var(t_env *e)
{
		e->zvar = 1;
		e->horyz = 860;
		e->vert = 540;
		e->zoom = 10;
		e->var_color = 0;
		e->max_z = 0;
		e->min_z = 0;
}

static int	red_exit(void)
{
		exit(1);
}

void		ft_error(char *str)
{
		ft_putendl(str);
		exit (1);
}

int			key_hook(int keycode, t_env *e)
{
		if (keycode == EXIT)
				close_image(e);
		if (keycode == UP || keycode == DOWN 
				|| keycode == LEFT || keycode == RIGHT)
				move_tab(keycode, e);
		if (keycode == PLUS || keycode == MOINS || keycode == 24 
				|| keycode == 27 )
				key_zoom(keycode, e);
		if (keycode == 43 || keycode == 47)
				e->zvar += (keycode == 43 ? -0.5 : 0.5);
		if (keycode == SPACE)
				init_var(e);
		if (keycode == 43 || keycode == 47 || keycode == SPACE)
		{
				new_image(e);
				print_map(e);
		}
		return (0);
}

int			main(int ac, char **av)
{
		t_env	e;

		init_var(&e);
		if (error(ac, av[1]))
				return (1);
		check_map(av[1], &e);
		create_tab(&e);
		fill_tab(av[1], &e);
		init_mlx(&e);
		save_color(&e);
		print_map(&e);
		mlx_hook(e.win, 2, (1L << 01), key_hook, &e);
		mlx_hook(e.win, 17, (1l << 17), red_exit, &e);
		mlx_loop(e.mlx);
}
