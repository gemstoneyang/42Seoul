/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:22:41 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/14 02:38:53 by wonyang          ###   ########seoul.kr  */
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

	printf("width : %d, height : %d\n", map_info->width, map_info->height);
	t_list *node;
	t_dot *dot;
	node = map_info->dot_list->next;
	while (node)
	{
		dot = (t_dot *)(node->content);
		printf("x: %d, y: %d, z: %d, color: %s\n", dot->x, dot->y, dot->z, dot->color);
		node = node->next;
	}
	return (0);
}

/*
int	main(void)
{
	void	*mlx;
	void	*win;
	int	WIN_WIDTH = 1000;
	int WIN_HEIGHT = 1000;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	win = (void *)win;
	void	*image = mlx_new_image(mlx, 1000, 1000);
	int	size_line1 = 0;
	int endian1 = 0;
	char	*ptr = mlx_get_data_addr(image, &bit_per_pixel1, &size_line1, &endian1);
	int	bit_per_pixel2 = 0;
	int	size_line2 = 0;
	int endian2 = 0;
	char	*ptr2 = mlx_get_data_addr(image, &bit_per_pixel2, &size_line2, &endian2);
	
	// for (int i = 0; i < 200; i++)
	// {
	// 	for (int j = 0; j < 200; j++)
	// 	{
	// 		ptr[i * WIN_WIDTH + j] = create_argb(0,255,110,110);
	// 	}
	// }
	for (int i =100 ; i< 300  ; i++)
	{
		for(int k = 100; k<300; k++){
			char *dst1;
			// 8 = sizeof(char)
			dst1 = ptr + (k * size_line1 + i * bit_per_pixel1 / 8 );
			*(unsigned int*)dst1 = create_argb(0,255,0,0);
		}
	}

	printf("%d %d\n", bit_per_pixel1, size_line1);
	printf("%d %d\n", bit_per_pixel2, size_line2);

	for (int i =500 ; i< 700  ; i++)
	{
		for(int k = 500; k<700; k++){
			char *dst2;
			// 8 = sizeof(char)
			dst2 = ptr2 + (k * size_line2 + i * bit_per_pixel2 / 8 );
			*(unsigned int*)dst2 = create_argb(0,0,255,0);
		}
	}

	mlx_put_image_to_window(mlx, win, image, 0, 0);

	// int color = create_argb(0,255,110,110);
	// for (int i = 0; i < 200; i++)
	// {
	// 	for (int j = 0; j < 200; j++)
	// 	{
	// 		mlx_pixel_put (mlx, win, 500+i, 500+j, color);
	// 	}
	// }

	mlx_loop(mlx);
}
*/
