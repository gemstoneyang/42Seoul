/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:06 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:12:16 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_delimiter(char c)
{
	if (c == ':')
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == 32)
		return (1);
	else
		return (0);
}

int	is_digit(char *str)
{
	int	length;

	length = 1;
	if (*str != '1')
		return (0);
	str++;
	while (is_number(*str))
	{
		if (*str != '0')
			return (0);
		str++;
		length++;
	}
	if (length % 3 == 1 && length >= 4)
		return (1);
	else
		return (0);
}
