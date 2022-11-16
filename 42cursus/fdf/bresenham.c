/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:36:51 by wonyang           #+#    #+#             */
/*   Updated: 2022/11/16 15:54:28 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_mlx *mlx, int ax, int ay, int bx, int by)
{
	int	dx;
	int	dy;
	int	p;

	dx = ax - bx;
	dy = ay - by;
	while (ax < bx || ay < by)
	{
		print_dot(mlx, ax, ay);
		if (dy / dx <= 0)
		{
			p = 2 * dy - dx;
			if (p < 0)
			{
				p = p + 2 * dy;
				ax++;
			}
			else
			{
				p = p + 2 * (dy - dx);
				ax++;
				ay++;
			}
		}
		else
		{
			p = 2 * dx - dy;
			if (p < 0)
			{
				p = p + 2 * dx;
				ay++;
			}
			else
			{
				p = p + 2 * (dx - dy);
				ax++;
				ay++;
			}
		}
	}
	print_dot(mlx, ax, ay);
}