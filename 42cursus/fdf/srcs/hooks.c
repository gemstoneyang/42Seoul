/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/02 18:32:21 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

static int	main_loop(t_param *param)
{
	t_mlx	*mlx;

	mlx = param->mlx;
	if (mlx->img != NULL)
		mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, mlx->win_x, mlx->win_y);
	mlx->ptr = mlx_get_data_addr(mlx->img, &(mlx->bit), &(mlx->lsize), &(mlx->end));
	print_screen(mlx, param->map, param->info);
	return (1);
}

static void	press_esc(t_param *param)
{
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	exit(0);
}

int	hooks(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		press_esc(param);
	main_loop(param);
	return (1);
}
