/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 14:18:00 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
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

int	hooks(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		press_esc(param);
	return (1);
}
