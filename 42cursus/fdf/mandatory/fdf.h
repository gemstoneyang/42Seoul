/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 15:49:06 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_dot
{
	int		x;
	int		y;
	int		z;
	char	*color;
}	t_dot;

typedef struct s_map
{
	int		height;
	int		width;
	t_dot	**matrix;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_x;
	int		win_y;
	int		bit;
	int		lsize;
	int		end;
	char	*ptr;
}	t_mlx;

typedef struct s_info
{
	int	xscale;
	int	yscale;
	int	zscale;
	int	xstart;
	int	ystart;
}	t_info;

typedef struct s_param
{
	t_map	*map;
	t_mlx	*mlx;
	t_info	*info;
}	t_param;

enum	e_keycode
{
	KEY_ESC = 53,
};

// map.c
t_map	*parse_map_info(char *map_name);

// parse.c
t_map	*parse_map(char *map_name);

// init.c
t_info	*init_info(t_mlx *mlx, t_map *map);
t_mlx	*init_mlx(int width, int height);

// screen.c
void	print_dot(t_mlx *mlx, t_dot dot);
void	print_screen(t_mlx *mlx, t_map *map, t_info *info);

// bresenham.c
void	print_line(t_mlx *mlx, t_dot a, t_dot b);

// hooks.c
int		hooks(int keycode, t_param *param);

// rotate.c
t_dot	isometric(t_dot dot);
t_dot	dot(t_dot dot, t_info *info);

#endif
