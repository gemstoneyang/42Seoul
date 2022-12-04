/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:28 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 17:42:31 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	move_object(t_param *param, int keycode)
{
	t_info	*info;

	info = param->info;
	if (keycode == KEY_UP)
		info->ystart += 50;
	else if (keycode == KEY_DOWN)
		info->ystart -= 50;
	else if (keycode == KEY_LEFT)
		info->xstart += 50;
	else if (keycode == KEY_RIGHT)
		info->xstart -= 50;
}

void	scale_object(t_param *param, int keycode)
{
	t_info	*info;

	info = param->info;
	if (keycode == KEY_LARR)
	{
		if (info->xscale > 1 && info->yscale > 1 && info->zscale > 1)
		{
			info->xscale -= 1;
			info->yscale -= 1;
			info->zscale -= 1;
		}
	}
	else if (keycode == KEY_RARR)
	{
		info->xscale += 1;
		info->yscale += 1;
		info->zscale += 1;
	}
}

void	scale_axis(t_param *param, int keycode)
{
	t_info	*info;

	info = param->info;
	if (keycode == KEY_E && info->xscale > 1)
		info->xscale -= 1;
	else if (keycode == KEY_R)
		info->xscale += 1;
	else if (keycode == KEY_D)
		info->yscale -= 1;
	else if (keycode == KEY_F)
		info->yscale += 1;
	else if (keycode == KEY_C)
		info->zscale -= 1;
	else if (keycode == KEY_V)
		info->zscale += 1;
}

void	rotate_object(t_param *param, int keycode)
{
	t_info	*info;

	info = param->info;
	if (keycode == KEY_Q)
		info->xtheta -= 10;
	else if (keycode == KEY_W)
		info->xtheta += 10;
	else if (keycode == KEY_A)
		info->ytheta -= 10;
	else if (keycode == KEY_S)
		info->ytheta += 10;
	else if (keycode == KEY_Z)
		info->ztheta -= 10;
	else if (keycode == KEY_X)
		info->ztheta += 10;
	if (info->xtheta == 360 || info->xtheta == -360)
		info->xtheta = 0;
	if (info->ytheta == 360 || info->ytheta == -360)
		info->ytheta = 0;
	if (info->ztheta == 360 || info->ztheta == -360)
		info->ztheta = 0;
}
