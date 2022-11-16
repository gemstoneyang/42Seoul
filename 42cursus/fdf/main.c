/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 15:53:40 by wonyang          ###   ########seoul.kr  */
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
	mlx = init_mlx(map_info->width * 100, map_info->height * 100);
	
	t_list *node;
	t_dot *dot;
	node = map_info->dot_list->next;
	while (node)
	{
		dot = (t_dot *)(node->content);
		// print_dot(mlx, dot->x * 50, dot->y * 50);
		// printf("x: %d, y: %d, z: %d, color: %s\n", dot->x, dot->y, dot->z, dot->color);
		node = node->next;
	}
	print_line(mlx, 100, 100, 300, 300);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 100, 100);
	mlx_loop(mlx->mlx);

	return (0);
}
