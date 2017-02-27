/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:57:20 by opettex-          #+#    #+#             */
/*   Updated: 2016/04/19 13:35:03 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		nb_char2(char *file)
{
	file = NULL;
	ft_error("error_file");
}

int			nb_chars(char *file)
{
	int		cmp;
	int		i;

	cmp = 0;
	i = 0;
	while (file[i])
	{
		if ((file[i] >= '0' && file[i] <= '9') || (file[i] == '-'))
		{
			cmp++;
			if (i > 0 && file[i] == '-' && !ft_isdigit(file[i + 1]))
				ft_error("error_file");
			while (file[i] && file[i] != ' ')
				i++;
		}
		else if (file[i] == ' ')
			i++;
		else
			nb_char2(file);
	}
	return (cmp);
}

void		check_map2(char *file, t_env *e, int cmp, int fd)
{
	e->max_line = 0;
	while ((cmp = get_next_line(fd, &file)) > 0)
	{
		if (e->max_line == 0)
			e->max_char = nb_chars(file);
		if (e->max_line != 0)
		{
			if (e->max_char != nb_chars(file))
				ft_error("invalid map");
		}
		e->max_line++;
		free(file);
	}
	if (cmp == -1 || (e->max_line == 0 && e->max_char == 0))
		ft_error("empty file");
	free(file);
}

int			check_map(char *file, t_env *e)
{
	int		cmp;
	int		fd;

	cmp = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (1);
	check_map2(file, e, cmp, fd);
	if (cmp < 0)
		ft_error("error");
	close(fd);
	return (0);
}

int			error(int nb_ac, char *file)
{
	if (nb_ac > 2)
	{
		ft_putendl("Wrong number file");
		return (1);
	}
	else if (nb_ac != 2 || file == 0)
	{
		ft_putendl("No file or wrong file");
		return (1);
	}
	return (0);
}
