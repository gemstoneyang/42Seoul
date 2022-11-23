/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/23 17:06:10 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("argument error");
	t_map *map_info;
	map_info = parse_map_info(argv[1]);

	parse_map(map_info, argv[1]);

	t_mlx	*mlx;
	mlx = init_mlx(1500, 1000);

	t_info *info;
	info = init_info();

	// t_dot *dot1 = (map_info->matrix)[0][3];
	// t_dot *dot2 = (map_info->matrix)[1][3];
	// print_line(mlx, dot(dot1, info), dot(dot2, info));
	// t_dot a = dot(dot1, info);
	// t_dot b = dot(dot2, info);
	// printf("a- x:%d y:%d\n", a.x, a.y);
	// printf("b- x:%d y:%d\n", b.x, b.y);
	// print_line(mlx, a, b);
	// print_dot(mlx, dot(dot1, info).x, dot(dot1, info).y);
	// print_dot(mlx, dot(dot2, info).x, dot(dot2, info).y);
	
	print_screen(mlx, map_info, info);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
