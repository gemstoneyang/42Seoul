/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:55:42 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/20 18:22:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	print_dot(t_mlx *mlx, int x, int y)
{
	char	*dst;

	if (mlx->win_height <= y || mlx->win_width <= x || x < 0 || y < 0)
		return ;
	dst = mlx->ptr + (y * (mlx->lsize) + x * (mlx->bit) / 8);
	*(unsigned int *)dst = create_argb(0, 255, 255, 255);
}

void	print_screen(t_mlx *mlx, t_map *map, t_info *info)
{
	int		i;
	int		j;
	t_dot	*dot1;
	t_dot	*dot2;

	i = 0;
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			dot1 = (map->matrix)[i][j];
			if (j != map->width - 1)
			{
				dot2 = (map->matrix)[i][j + 1];
				print_line(mlx, dot(dot1, info), dot(dot2, info));
			}
			if (i != map->height - 1)
			{
				dot2 = (map->matrix)[i + 1][j];
				print_line(mlx, dot(dot1, info), dot(dot2, info));
			}
		}
		i++;
	}
}

t_mlx	*init_mlx(int width, int height)
{
	t_mlx	*m;

	m = (t_mlx *)ft_malloc(sizeof(t_mlx));
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, width, height, "fdf");
	m->img = mlx_new_image(m->mlx, width, height);
	m->win_width = width;
	m->win_height = height;
	m->bit = 0;
	m->lsize = 0;
	m->end = 0;
	m->ptr = mlx_get_data_addr(m->img, &(m->bit), &(m->lsize), &(m->end));
	return (m);
}
