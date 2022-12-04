/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:46:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 15:47:03 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

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

// map_bonus.c
t_map	*parse_map_info(char *map_name);

// parse_bonus.c
t_map	*parse_map(char *map_name);

// init_bonus.c
t_info	*init_info(t_mlx *mlx, t_map *map);
t_mlx	*init_mlx(int width, int height);

// screen_bonus.c
void	print_dot(t_mlx *mlx, t_dot dot);
void	print_screen(t_mlx *mlx, t_map *map, t_info *info);

// bresenham_bonus.c
void	print_line(t_mlx *mlx, t_dot a, t_dot b);

// hooks_bonus.c
int		hooks(int keycode, t_param *param);

// rotate_bonus.c
t_dot	rotate_x(t_dot dot, double theta);
t_dot	rotate_y(t_dot dot, double theta);
t_dot	rotate_z(t_dot dot, double theta);
t_dot	isometric(t_dot dot);
t_dot	dot(t_dot dot, t_info *info);

#endif
