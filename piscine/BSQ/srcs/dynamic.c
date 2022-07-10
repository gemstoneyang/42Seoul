/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongmin <jeongmin@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:34:02 by jeongmin          #+#    #+#             */
/*   Updated: 2022/06/08 23:50:10 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

void	**array_gen(int x, int y, unsigned long p_size, unsigned long size)
{
	void	**array;
	int		i;

	i = 0;
	array = malloc(p_size * x);
	if (!array)
		return (array);
	while (i < x)
	{
		array[i] = malloc(size * y);
		if (!array[i])
		{
			free_multi_array(&array, i);
			return (0);
		}
		i++;
	}
	return (array);
}

void	free_multi_array(void ***array, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free((*array)[i]);
		(*array)[i] = 0;
		i++;
	}
	free(*array);
	*array = 0;
}

void	final_free(char ***map, int ***bsq, int x)
{
	free_multi_array((void ***)map, x);
	free_multi_array((void ***)bsq, x);
}

int	init(char ***map, int ***bsq, int x, int y)
{
	(*map) = (char **)array_gen(x, y, sizeof(char *), sizeof(char));
	if (!(*map))
		return (ERROR);
	(*bsq) = (int **)array_gen(x, y, sizeof(int *), sizeof(int));
	if (!(*bsq))
	{
		free_multi_array((void ***)map, x);
		return (ERROR);
	}
	return (0);
}
