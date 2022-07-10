/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:07:03 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/30 10:52:38 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_rcross(int board[][10], int x, int y)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (++i < 10 && --j >= 0)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	i = x;
	j = y;
	while (--i >= 0 && ++j < 10)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	return (1);
}

int	check_cross(int board[][10], int x, int y)
{
	int	i;
	int	j;

	i = x;
	j = y;
	while (--i >= 0 && --j >= 0)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	i = x;
	j = y;
	while (++i < 10 && ++j < 10)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	return (1);
}

int	can_place(int board[][10], int x, int y)
{
	int	i;
	int	j;

	i = -1;
	j = y;
	while (++i < 10)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	i = x;
	j = -1;
	while (++j < 10)
	{
		if (board[i][j])
		{
			return (0);
		}
	}
	if (check_cross(board, x, y) == 0)
		return (0);
	return (check_rcross(board, x, y));
}

int	recursive(int board[][10], int depth, char *queens, int count)
{
	int	i;

	if (depth >= 10)
	{
		write(1, queens, 10);
		write(1, "\n", 1);
		return (count + 1);
	}
	i = 0;
	while (i < 10)
	{
		if (can_place(board, i, depth))
		{
			board[i][depth] = 1;
			queens[depth] = i + '0';
			count = recursive(board, depth + 1, queens, count);
			board[i][depth] = 0;
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int		board[10][10];
	char	queens[10];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (recursive(board, 0, queens, 0));
}
