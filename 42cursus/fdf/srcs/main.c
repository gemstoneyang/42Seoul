/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/01 20:57:38 by wonyang          ###   ########seoul.kr  */
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
	write(1, "map_info init\n", 14);

	parse_map(map, argv[1]);
	write(1, "map_parse init\n", 15);

	t_mlx	*mlx;
	mlx = init_mlx(1500, 1000);

	t_info *info;
	info = init_info(mlx, map);

	print_screen(mlx, map, info);
	write(1, "print_screen init\n", 17);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
