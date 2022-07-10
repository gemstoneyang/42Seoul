/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:26:29 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/21 17:38:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print(int j, int col, char *str)
{
	if (j == 0)
		ft_putchar(str[0]);
	else if (j == col - 1)
		ft_putchar(str[2]);
	else
		ft_putchar(str[1]);
}

void	rush(int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i == 0)
				print(j, col, "ABC");
			else if (i == row - 1)
				print(j, col, "ABC");
			else
				print(j, col, "B B");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
