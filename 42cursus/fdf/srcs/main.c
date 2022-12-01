/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/01 22:04:43 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	t_info	*info;

	if (argc != 2)
		error_exit("argument error");
	map = parse_map_info(argv[1]);
	parse_map(map, argv[1]);
	mlx = init_mlx(1920, 1080);
	info = init_info(mlx, map);
	print_screen(mlx, map, info);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
