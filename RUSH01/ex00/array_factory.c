/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_factory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:12:51 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 23:11:43 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_single_array(int *array);

int	**int_multi_array_factory(int row, int col)
{
	int	**array;
	int	i;
	int	j;

	i = 0;
	array = (int **)malloc(sizeof(int *) * row);
	if (array == 0)
		return (0);
	while (i < row)
	{
		array[i] = (int *)malloc(sizeof(int) * col);
		if (array[i] == 0)
		{	
			while (--i >= 0)
				free_single_array(array[i]);
			free(array);
			array = 0;
			return (0);
		}
		j = -1;
		while (++j < col)
			array[i][j] = 0;
		i++;
	}
	return (array);
}

int	*int_array_factory(int n)
{
	int	*array;
	int	i;

	i = -1;
	array = (int *)malloc(sizeof(int) * n);
	while (++i < n)
		array[i] = 0;
	return (array);
}

void	free_single_array(int *array)
{
	free(array);
	array = 0;
}

void	free_multi_array(int **array, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(array[i]);
		array[i] = 0;
		i++;
	}
	free(array);
	array = 0;
}
