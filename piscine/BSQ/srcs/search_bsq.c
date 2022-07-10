/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bsq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:24:10 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/09 05:17:31 by jeongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	change_cor(int cor[3], int x, int y, int max_bsq)
{
	cor[0] = x;
	cor[1] = y;
	cor[2] = max_bsq;
}

int	init_bsq(char **map, int **bsq, t_info map_info, int cor[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info.x)
	{
		j = 0;
		while (j < map_info.y)
		{
			if (map[i][j] == map_info.charset[1])
				bsq[i][j] = 0;
			else if (map[i][j] == map_info.charset[0])
			{
				bsq[i][j] = 1;
				if (cor[2] == 0)
					change_cor(cor, i, j, 1);
			}
			else
				return (ERROR);
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_bsq(int **bsq, t_info map_info, int cor[3])
{
	int	i;
	int	j;

	i = 1;
	while (i < map_info.x)
	{
		j = 1;
		while (j < map_info.y)
		{
			if (bsq[i][j] == 0)
			{
				j++;
				continue ;
			}
			else
			{
				bsq[i][j] = min(bsq[i][j -1], bsq[i -1][j], bsq[i -1][j -1]);
				if (bsq[i][j] > cor[2])
					change_cor(cor, i, j, bsq[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	print_result(char **map, int cor[3], t_info map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info.x)
	{
		j = 0;
		while (j < map_info.y)
		{
			if (cor[0] - cor[2] + 1 <= i && i <= cor[0] \
					&& cor[1] - cor[2] + 1 <= j && j <= cor[1])
				write(1, &map_info.charset[2], 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	bsq_main(char **map, int **bsq, t_info map_info)
{
	int	cor[3];

	change_cor(cor, -1, -1, 0);
	if (init_bsq(map, bsq, map_info, cor) == ERROR)
		return (ERROR);
	fill_bsq(bsq, map_info, cor);
	print_result(map, cor, map_info);
	return (0);
}
