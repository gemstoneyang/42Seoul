/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 16:45:44 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"
#include <stdio.h>

int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("argument error");
	t_map *map_info;
	map_info = parse_map_info(argv[1]);
	parse_map(map_info, argv[1]);

	t_mlx	*mlx;
	mlx = init_mlx(1000, 1000);
	
	t_dot ***matrix;
	t_dot *dot;
	matrix = map_info->matrix;
	for (int i = 0; i < map_info->height; i++)
	{
		for (int j = 0; j < map_info->width; j++)
		{
			dot = matrix[i][j];
			print_dot(mlx, dot->x * 50, dot->y * 50);
		}
	}
	
	t_dot a, b;
	a.x = 100;
	a.y = 300;
	b.x = 300;
	b.y = 100;
	// print_dot(mlx, a.x, a.y);
	// print_dot(mlx, b.x, b.y);

	print_line(mlx, a, b);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
