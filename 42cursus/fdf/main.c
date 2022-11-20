/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 18:10:44 by wonyang          ###   ########seoul.kr  */
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

	t_info *info;
	info = init_info();
	
	print_screen(mlx, map_info, info);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);

	return (0);
}
