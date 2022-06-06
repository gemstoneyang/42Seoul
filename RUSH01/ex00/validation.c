/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:49:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/29 12:52:13 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	input_form_validation(char *input)
{
	int		i;
	char	c;

	i = 0;
	while (input[i] != '\0')
	{
		c = input[i];
		if (!(('1' <= c && c <= '9') || c == ' ' || c == '\n'))
			return (-1);
		while (input[i] != '\0' && (input[i] == ' ' || input[i] == '\n'))
			i++;
		if (input[i] == '\0')
			break ;
		if (input[i + 1] != ' ' && input[i + 1] != '\0' && input[i + 1] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	input_value_validation(char *input)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 0;
	max = 0;
	while (input[i] != '\0')
	{
		while (input[i] != '\0' && (input[i] == ' ' || input[i] == '\n'))
			i++;
		if (input[i] == '\0')
			break ;
		if (max < input[i] - '0')
			max = input[i] - '0';
		count++;
		i++;
	}
	if (count % 4 != 0 || max > count / 4)
		return (-1);
	if (!(count / 4 <= 9))
		return (-1);
	return (count / 4);
}

int	input_validation(char *input)
{
	if (input_form_validation(input) == -1)
		return (-1);
	return (input_value_validation(input));
}
