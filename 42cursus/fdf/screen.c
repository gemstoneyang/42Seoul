/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:55:42 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 15:53:17 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

static int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	print_dot(t_mlx *mlx, int x, int y)
{
	char	*dst;

	dst = mlx->ptr + (y * (mlx->lsize) + x * (mlx->bit) / 8);
	*(unsigned int *)dst = create_argb(0, 255, 255, 255);
}

t_mlx	*init_mlx(int width, int height)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx));
	if (!m)
		error_exit("malloc error");
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, width, height, "test");
	m->img = mlx_new_image(m->mlx, width, height);
	m->win_width = width;
	m->win_height = height;
	m->bit = 0;
	m->lsize = 0;
	m->end = 0;
	m->ptr = mlx_get_data_addr(m->img, &(m->bit), &(m->lsize), &(m->end));
	return (m);
}
