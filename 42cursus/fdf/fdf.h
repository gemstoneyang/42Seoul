/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:45:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 16:50:50 by wonyang          ###   ########seoul.kr  */
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

// map.c
t_map	*parse_map_info(char *map_name);

// parse.c
void	parse_map(t_map *map_info, char *map_name);

// screen.c
t_mlx	*init_mlx(int width, int height);
void	print_dot(t_mlx *mlx, int x, int y);

// bresenham.c
void	print_line(t_mlx *mlx, t_dot a, t_dot b);

// exit.c
void	perror_exit(char *msg, int code);
void	error_exit(char *msg);

// utils.c
int		is_integer(char *str);

// ftcntl.c
int		ft_open(const char *path);
void	ft_close(int fd);
void	*ft_malloc(size_t size);

#endif
