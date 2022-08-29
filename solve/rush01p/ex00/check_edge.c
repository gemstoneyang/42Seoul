/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_edge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:54:06 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 10:25:53 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*int_array_factory(int n);
void	free_single_array(int *array);

int	count_block(int *array, int size)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (max < array[i])
		{
			count++;
			max = array[i];
		}
		i++;
	}
	return (count);
}

int	check_edge(int *array, int left, int right, int size)
{
	int	*rev_array;
	int	i;

	rev_array = int_array_factory(size);
	if (rev_array == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		rev_array[i] = array[size - i - 1];
		i++;
	}
	if (count_block(array, size) == left \
			&& count_block(rev_array, size) == right)
	{
		free_single_array(rev_array);
		return (1);
	}
	free_single_array(rev_array);
	return (0);
}
