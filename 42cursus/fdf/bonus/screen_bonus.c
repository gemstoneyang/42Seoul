/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:19 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 17:10:53 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include "libft.h"

static int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

static int	hex_to_int(char *hex)
{
	int	i;
	int	res;

	if (!hex || ft_strlen(hex) != 8)
		return (create_argb(0, 255, 255, 255));
	i = 2;
	res = 0;
	while (hex[i])
	{
		res <<= 4;
		if (ft_isdigit(hex[i]))
			res += hex[i] - '0';
		else
			res += ft_tolower(hex[i]) - 'a' + 10;
		i++;
	}
	return (res);
}

void	fill_black(t_mlx *mlx)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (i < mlx->win_y)
	{
		j = 0;
		while (j < mlx->win_x)
		{
			dst = mlx->ptr + (i * (mlx->lsize) + j * (mlx->bit) / 8);
			*(unsigned int *)dst = create_argb(0, 0, 0, 0);
			j++;
		}
		i++;
	}
}

void	print_dot(t_mlx *mlx, t_dot dot)
{
	char	*dst;

	if (mlx->win_y <= dot.y || mlx->win_x <= dot.x || dot.x < 0 || dot.y < 0)
		return ;
	dst = mlx->ptr + (dot.y * (mlx->lsize) + dot.x * (mlx->bit) / 8);
	if (dot.color == NULL)
		*(unsigned int *)dst = create_argb(0, 255, 255, 255);
	else
		*(unsigned int *)dst = hex_to_int(dot.color);
}

void	print_screen(t_mlx *mlx, t_map *map, t_info *info)
{
	int		i;
	int		j;
	t_dot	dot1;
	t_dot	dot2;

	i = 0;
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			dot1 = (map->matrix)[i][j];
			if (j != map->width - 1)
			{
				dot2 = (map->matrix)[i][j + 1];
				print_line(mlx, dot(dot1, info), dot(dot2, info));
			}
			if (i != map->height - 1)
			{
				dot2 = (map->matrix)[i + 1][j];
				print_line(mlx, dot(dot1, info), dot(dot2, info));
			}
		}
		i++;
	}
}
