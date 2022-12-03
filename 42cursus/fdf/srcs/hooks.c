/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:05:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/03 12:50:57 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

static void	press_esc(t_param *param)
{
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	exit(0);
}

int	hooks(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
		press_esc(param);
	return (1);
}
