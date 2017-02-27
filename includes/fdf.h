/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opettex- <opettex-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:19:10 by opettex-          #+#    #+#             */
/*   Updated: 2016/07/01 17:14:14 by opettex-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define WIN_X 1920
# define WIN_Y 1080
# define IMG_X 1920
# define IMG_Y 1080
# define WHITE 0xFFFFFF
# define TEAL 0x008080
# define LIGHTSEAGREEN 0x20B2AA
# define TURQUOISE 0x40E0D0
# define ACQUAMARINE 0x7FFFD4
# define PALEGREEN 0x98FB98
# define YELLOWGREEN 0x9ACD32
# define GOLD  0xFFD700
# define PERU 0xCD853F
# define ORANGE 0xFFA500
# define ORANGERED 0xFF4500
# define RED 0xFF0000
# define FIREBRICK 0xB22222
# define MAROON 0x800000
# define SIENNA 0xA0522D
# define SADDLEBROWN 0x8B4513
# define DOWN 125
# define UP 126
# define LEFT 123
# define RIGHT 124
# define EXIT 53
# define PLUS 69
# define SPACE 49
# define MOINS 78
# define COLOR 8

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	int						x;
	int						y;
	int						max_line;
	int						max_char;
	char					*line;
	char					*data;
	int						bpp;
	int						end;
	int						sl;
	double					zoom;
	int						dezoom;
	int						color;
	int						var_color;
	double					max_z;
	double					min_z;
	double					distance;
	float					zvar;
	void					*img;
	int						**tab_color;
	double					**tab;
	char					*tmp;
	int						horyz;
	int						vert;
	int						sx;
	int						sy;
	int						ex;
	int						ey;
	int						dx;
	int						dy;
	int						cmp;
	int						cumul;
	double					x_tr;
	double					y_tr;
	int						fd;
	int						i;
	int						x_fill;
	int						y_fill;
	int						xd;
	int						yd;

}							t_env;

void						ft_error(char *str);
void						key_zoom(int keycode, t_env *e);
void						ft_hook(int keycode, t_env *e);
void						move_tab(int keycode, t_env *e);
void						color_max_z(t_env *e);
void						color_z(t_env *e, double z);
void						save_color(t_env *e);
void						init_mlx(t_env *e);
void						new_image(t_env *e);
int							get_next_line(int const fd, char **line);
void						trace_line(t_env *e, int color);
void						trace_2(t_env *e, int xinc, int yinc, int color);
void						trace_3(t_env *e, int xinc, int yinc, int color);
void						draw_iso(t_env *e);
int							error(int nb_ac, char *file);
int							check_file(char *file);
int							nb_chars(char *file);
int							check_map(char *file, t_env *e);
void						print_map(t_env *e);
void						create_tab(t_env *e);
void						fill_tab(char *file, t_env *e);
void						put_pixel_to_img(t_env *e, int x, int y, int color);
void						close_image(t_env *e);
void						clear_map(t_env *e);

#endif
