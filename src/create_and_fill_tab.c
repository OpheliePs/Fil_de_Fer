/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_fill_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 02:38:00 by opettex-          #+#    #+#             */
/*   Updated: 2016/04/12 21:00:23 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		save_color(t_env *e)
{
	int x;
	int y;

	color_max_z(e);
	if (!(e->tab_color = (int **)malloc(sizeof(int *) * e->max_line)))
			ft_error("Error Malloc");
	y = -1;
	while (++y < e->max_line)
	{
		x = -1;
		if (!(e->tab_color[y] = (int*)malloc(sizeof(int) * e->max_char)))
				ft_error("Error Malloc");
		while (++x < e->max_char)
		{
			color_z(e, e->tab[y][x]);
			e->tab_color[y][x] = e->color;
		}
	}
}

void		create_tab(t_env *e)
{
	int y;
	int x;

	if (!(e->tab = (double **)malloc(sizeof(double *) * e->max_line)))
			ft_error("Malloc error");
	y = -1;
	while (++y < e->max_line)
	{
		if (!(e->tab[y] = (double *)malloc(sizeof(double) * e->max_char)))
				ft_error("Malloc error");
		x = -1;
		while (++x < e->max_char)
			e->tab[y][x] = 0;
	}
	if (e->tab == NULL)
			ft_error("Malloc error");
}

static void	fill_tab_2(t_env *e, char *line)
{
	e->tab[e->y_fill][e->x_fill] = ft_atoi(line + e->i);
	e->tmp = ft_itoa(e->tab[e->y_fill][e->x_fill]);
	e->i += ft_strlen(e->tmp);
	free(e->tmp);
	++e->x_fill;
}

void		fill_tab(char *file, t_env *e)
{
	char	*line;

	if (!(e->fd = open(file, O_RDONLY)))
		exit(1);
	e->y_fill = -1;
	while (get_next_line(e->fd, &line) > 0)
	{
		e->y_fill++;
		e->i = 0;
		e->x_fill = 0;
		while (line[e->i])
		{
			if (line[e->i] && line[e->i] >= '0' && line[e->i] <= '9')
				fill_tab_2(e, line);
			else
				++e->i;
		}
		free(line);
	}
	free(line);
}
