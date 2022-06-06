/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:24:55 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 23:13:00 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*int_array_factory(int n);
void	free_single_array(int *array);
void	ft_putchar(char c);
int		check_board(int **board, int size);
int		check_edge(int *array, int left, int right, int size);
int		recursion(int **board, int **edge, int size, int *nxt_coor);

int	check_updown(int **board, int **edge, int size)
{
	int	*array;
	int	i;
	int	j;

	array = int_array_factory(size);
	if (array == 0)
		return (0);
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			array[i] = board[i][j];
			i++;
		}
		if (check_edge(array, edge[0][j], edge[1][j], size) == 0)
		{
			free_single_array(array);
			return (0);
		}
		j++;
	}
	free_single_array(array);
	return (1);
}

void	result_print(int **board, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = board[i][j] + '0';
			ft_putchar(c);
			if (j != size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	check_end_case(int **board, int **edge, int size, int *coor)
{
	if (coor[0] >= size)
	{
		if (check_updown(board, edge, size) == 1)
		{
			result_print(board, size);
			return (2);
		}	
		return (0);
	}
	return (1);
}

int	change_board(int **board, int **edge, int size, int *c)
{
	int	nxt_coor[2];
	int	i;

	i = 0;
	while (++i < size + 1)
	{
		board[c[0]][c[1]] = i;
		nxt_coor[0] = c[0];
		nxt_coor[1] = c[1] + 1;
		if (nxt_coor[1] >= size)
		{
			if (!check_edge(board[c[0]], edge[2][c[0]], edge[3][c[0]], size))
			{	
				board[c[0]][c[1]] = 0;
				continue ;
			}
			nxt_coor[0] = c[0] + 1;
			nxt_coor[1] = 0;
		}
		if (recursion(board, edge, size, nxt_coor) == 2)
			return (2);
		board[c[0]][c[1]] = 0;
	}
	return (0);
}

int	recursion(int **board, int **edge, int size, int *c)
{
	int	res;

	if (check_board(board, size))
		return (0);
	res = check_end_case(board, edge, size, c);
	if (res != 1)
		return (res);
	return (change_board(board, edge, size, c));
}
