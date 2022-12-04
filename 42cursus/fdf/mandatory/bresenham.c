/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:36:51 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 13:20:31 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "libft.h"

static t_dot	change_coor(t_dot tmp, int dx, int dy)
{
	t_dot	res;

	res.x = tmp.x + dx;
	res.y = tmp.y + dy;
	res.color = tmp.color;
	return (res);
}

static t_dot	update_weight(t_dot a, t_dot b)
{
	t_dot	weight;

	weight.x = 1;
	weight.y = 1;
	if (a.x > b.x)
		weight.x = -1;
	if (a.y > b.y)
		weight.y = -1;
	return (weight);
}

static void	small_gradient(t_mlx *mlx, t_dot a, t_dot b, t_dot d)
{
	int		p;
	t_dot	w;
	t_dot	tmp;

	tmp = a;
	p = 2 * d.y - d.x;
	w = update_weight(a, b);
	while (tmp.x != b.x || tmp.y != b.y)
	{
		print_dot(mlx, tmp);
		if (p < 0)
		{
			p = p + 2 * d.y;
			tmp = change_coor(tmp, w.x, 0);
		}
		else
		{
			p = p + 2 * (d.y - d.x);
			tmp = change_coor(tmp, w.x, w.y);
		}
	}
	print_dot(mlx, tmp);
}

static void	big_gradient(t_mlx *mlx, t_dot a, t_dot b, t_dot d)
{
	int		p;
	t_dot	w;
	t_dot	tmp;

	tmp = a;
	p = 2 * d.x - d.y;
	w = update_weight(a, b);
	while (tmp.x != b.x || tmp.y != b.y)
	{
		print_dot(mlx, tmp);
		if (p < 0)
		{
			p = p + 2 * d.x;
			tmp = change_coor(tmp, 0, w.y);
		}
		else
		{
			p = p + 2 * (d.x - d.y);
			tmp = change_coor(tmp, w.x, w.y);
		}
	}
	print_dot(mlx, tmp);
}

void	print_line(t_mlx *mlx, t_dot a, t_dot b)
{
	t_dot	d;

	d.x = ft_abs(a.x - b.x);
	d.y = ft_abs(a.y - b.y);
	if (d.x && (double)d.y / (double)d.x <= 1)
		small_gradient(mlx, a, b, d);
	else
		big_gradient(mlx, a, b, d);
}
