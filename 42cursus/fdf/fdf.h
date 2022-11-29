/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/29 23:11:25 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

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
	t_dot	***matrix;
}	t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		win_width;
	int		win_height;
	int		bit;
	int		lsize;
	int		end;
	char	*ptr;
}	t_mlx;

typedef struct s_info
{
	int	xscale;
	int yscale;
	int	zscale;
	int	xstart;
	int ystart;
}	t_info;

// map.c
t_map	*parse_map_info(char *map_name);

// parse.c
void	parse_map(t_map *map_info, char *map_name);

// screen.c
t_mlx	*init_mlx(int width, int height);
void	print_dot(t_mlx *mlx, int x, int y);
void	print_screen(t_mlx *mlx, t_map *map, t_info *info);

// bresenham.c
void	print_line(t_mlx *mlx, t_dot a, t_dot b);

// filter.c
t_info	*init_info(t_mlx *mlx, t_map *map);
t_dot	dot(t_dot *dot, t_info *info);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

// utils.c
int		is_integer(char *str);

// ftcntl.c
int		ft_open(const char *path);
void	ft_close(int fd);
void	*ft_malloc(size_t size);

// rotate.c
t_dot	rotate_x(t_dot dot, double theta);
t_dot	rotate_y(t_dot dot, double theta);
t_dot	rotate_z(t_dot dot, double theta);
t_dot	isometric(t_dot dot);

#endif
