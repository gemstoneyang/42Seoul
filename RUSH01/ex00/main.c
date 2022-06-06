/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:02:32 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 22:15:35 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_error(void);
int		input_validation(char *input);
int		**int_multi_array_factory(int row, int col);
void	free_multi_array(int **array, int col);
int		recursion(int **board, int **edge, int size, int *c);

int	**convert_input_value(char *input, int size)
{
	int	**result;
	int	i;
	int	j;
	int	count;

	result = int_multi_array_factory(4, size);
	if (result == 0)
		return (0);
	count = 0;
	while (input[count] == ' ' || input[count] == '\n')
		count++;
	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < size)
		{
			result[i][j] = input[count] - '0';
			j++;
			count++;
			while (input[count] == ' ' || input[count] == '\n')
				count++;
		}
	}
	return (result);
}

void	rush(int **edge, int size)
{
	int	**board;
	int	coor[2];
	int	result;

	board = int_multi_array_factory(size, size);
	if (board == 0)
	{
		ft_print_error();
		return ;
	}
	coor[0] = 0;
	coor[1] = 0;
	result = recursion(board, edge, size, coor);
	if (result != 2)
		ft_print_error();
	free_multi_array(board, size);
}

int	main(int argc, char *argv[])
{
	int	size;
	int	**res;

	if (argc != 2)
	{
		ft_print_error();
		return (0);
	}
	size = input_validation(argv[1]);
	if (size < 1)
	{
		ft_print_error();
		return (0);
	}
	res = convert_input_value(argv[1], size);
	if (res == 0)
	{
		ft_print_error();
		return (0);
	}
	rush(res, size);
	free_multi_array(res, 4);
	return (0);
}
