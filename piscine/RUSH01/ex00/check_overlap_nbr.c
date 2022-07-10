/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlap_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:47:59 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 10:27:49 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*int_array_factory(int n);
void	free_single_array(int *array);

int	is_same_number(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == 0)
		{
			i++;
			continue ;
		}
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_col_number(int **board, int size)
{
	int	i;
	int	j;
	int	*array;

	array = int_array_factory(size);
	if (array == 0)
		return (1);
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			array[i] = board[i][j];
			i++;
		}
		if (is_same_number(array, size) == 1)
		{
			free_single_array(array);
			return (1);
		}
		j++;
	}
	free_single_array(array);
	return (0);
}

int	check_board(int **board, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_same_number(board[i], size) == 1)
			return (1);
		i++;
	}
	if (check_col_number(board, size) == 1)
		return (1);
	return (0);
}
