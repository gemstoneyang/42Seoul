/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/01 22:00:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_exit("argument error");
	t_map *map;
	map = parse_map_info(argv[1]);

	parse_map(map, argv[1]);

	t_mlx	*mlx;
	mlx = init_mlx(1920, 1080);

	t_info *info;
	info = init_info(mlx, map);

	print_screen(mlx, map, info);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
