/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 18:12:27 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf_bonus.h"
#include "mlx.h"

static void	free_all(t_param *param)
{
	int		i;
	int		j;
	t_dot	dot;

	i = 0;
	while (i < param->map->height)
	{
		j = 0;
		while (j < param->map->width)
		{
			dot = (param->map->matrix)[i][j];
			free(dot.color);
			j++;
		}
		free((param->map->matrix)[i]);
		i++;
	}
	free(param->map->matrix);
	free(param->map);
	free(param->info);
	free(param->mlx);
}

static void	press_esc(t_param *param)
{
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	free_all(param);
	exit(0);
}

static void	init_isomatric(t_param *param)
{
	t_info	*info;

	info = param->info;
	info->projection = 0;
	info->xtheta = 0;
	info->ytheta = 0;
	info->ztheta = 0;
}

static void	init_parallel(t_param *param)
{
	t_info	*info;

	info = param->info;
	info->projection = 1;
	info->xtheta = 0;
	info->ytheta = 0;
	info->ztheta = 0;
}

int	hooks(int keycode, t_param *p)
{
	if (keycode == KEY_ESC)
		press_esc(p);
	else if (keycode == KEY_UP || keycode == KEY_DOWN || \
	keycode == KEY_LEFT || keycode == KEY_RIGHT)
		move_object(p, keycode);
	else if (keycode == KEY_LARR || keycode == KEY_RARR)
		scale_object(p, keycode);
	else if (keycode == KEY_Q || keycode == KEY_W || \
	keycode == KEY_A || keycode == KEY_S || \
	keycode == KEY_Z || keycode == KEY_X)
		rotate_object(p, keycode);
	else if (keycode == KEY_E || keycode == KEY_R || \
	keycode == KEY_D || keycode == KEY_F || \
	keycode == KEY_C || keycode == KEY_V)
		scale_axis(p, keycode);
	else if (keycode == KEY_O)
		init_isomatric(p);
	else if (keycode == KEY_P)
		init_parallel(p);
	fill_black(p->mlx);
	print_screen(p->mlx, p->map, p->info);
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->win, p->mlx->img, 0, 0);
	return (1);
}
