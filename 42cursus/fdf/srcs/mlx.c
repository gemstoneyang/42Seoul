/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:36:07 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/02 18:37:35 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_mlx	*init_mlx(int width, int height)
{
	t_mlx	*m;

	m = (t_mlx *)ft_malloc(sizeof(t_mlx));
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, width, height, "fdf");
	m->img = mlx_new_image(m->mlx, width, height);
	m->win_x = width;
	m->win_y = height;
	m->bit = 0;
	m->lsize = 0;
	m->end = 0;
	m->ptr = mlx_get_data_addr(m->img, &(m->bit), &(m->lsize), &(m->end));
	return (m);
}
