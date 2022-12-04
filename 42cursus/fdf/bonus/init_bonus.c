/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:36:07 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 17:49:47 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include "libft.h"

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

t_info	*init_info(t_mlx *mlx, t_map *map)
{
	t_info	*info;
	int		scale;

	mlx = (void *)mlx;
	info = (t_info *)ft_malloc(sizeof(t_info));
	scale = max(1, mlx->win_x / map->width / 4);
	info->xscale = scale;
	info->yscale = scale;
	info->zscale = scale;
	info->xtheta = 0;
	info->ytheta = 0;
	info->ztheta = 0;
	info->xstart = 200 - map->width;
	info->ystart = 600 + map->height / 2;
	info->projection = 0;
	return (info);
}

t_mlx	*init_mlx(int width, int height)
{
	t_mlx	*m;

	m = (t_mlx *)ft_malloc(sizeof(t_mlx));
	m->mlx = mlx_init();
	if (m->mlx == NULL)
		ft_error_exit("mlx init error");
	m->win = mlx_new_window(m->mlx, width, height, "fdf");
	if (m->win == NULL)
		ft_error_exit("mlx window error");
	m->img = mlx_new_image(m->mlx, width, height);
	if (m->img == NULL)
		ft_error_exit("mlx image error");
	m->win_x = width;
	m->win_y = height;
	m->bit = 0;
	m->lsize = 0;
	m->end = 0;
	m->ptr = mlx_get_data_addr(m->img, &(m->bit), &(m->lsize), &(m->end));
	return (m);
}
