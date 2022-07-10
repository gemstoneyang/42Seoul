/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:44:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/22 12:44:56 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int col, int row);

int	is_exception(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (!('0' <= input[i] && input[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	string_to_int(char *input)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (input[i] != '\0')
	{
		if (res > 214748364 && input[i] - '0' >= 8)
			return (-1);
		res *= 10;
		res += input[i] - '0';
		i++;
	}
	return (res);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;

	if (argc != 3 || is_exception(argv[1]) == 1 || is_exception(argv[2]) == 1)
		return (0);
	a = string_to_int(argv[1]);
	b = string_to_int(argv[2]);
	if (a <= 0 || b <= 0)
		return (0);
	rush(a, b);
	return (0);
}
