/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:14:54 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:07:51 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "field_parser.h"

int	number_field_parse_digit_dict(t_digit_dict *digit_dict, int length)
{
	t_digit_dict	*new_digit_dict_element;

	new_digit_dict_element = \
		(t_digit_dict *)malloc(sizeof(t_digit_dict));
	if (new_digit_dict_element == 0)
		return (0);
	new_digit_dict_element->digit = length;
	new_digit_dict_element->next = digit_dict -> next;
	digit_dict -> next = new_digit_dict_element;
	return (1);
}

int	number_field_parse_dict(t_dict *dict, char *buff)
{
	t_dict			*new_dict_element;

	new_dict_element = (t_dict *)malloc(sizeof(t_dict));
	if (new_dict_element == 0)
		return (0);
	new_dict_element->key = ft_atoi(buff);
	new_dict_element->next = dict->next;
	dict->next = new_dict_element;
	return (1);
}

int	number_field_parse(t_dict *dict, t_digit_dict *digit_dict, \
		char *buff, int *idx)
{
	int				length;

	length = 0;
	--(*idx);
	while (is_number(buff[++(*idx)]))
		length++;
	if (length == 0)
		return (0);
	if (length >= 4 && is_digit(buff))
	{
		if (!number_field_parse_digit_dict(digit_dict, length))
			return (0);
		if (is_delimiter(buff[*idx]) || is_space(buff[*idx]))
			return (2);
	}
	else
	{
		if (!number_field_parse_dict(dict, buff))
			return (0);
		if (is_delimiter(buff[*idx]) || is_space(buff[*idx]))
			return (1);
	}
	return (0);
}

int	space_field_parse(char *buff, int *idx)
{
	int	space_length;

	space_length = 0;
	while (is_space(buff[*idx]))
	{
		space_length++;
		*idx += 1;
	}
	if (is_delimiter(buff[*idx]) || is_printable(buff[*idx]))
		return (space_length);
	else
		return (-1);
}

char	*character_field_parse(char *buff, int *idx)
{
	int		i;
	int		k;
	int		length;
	char	*val;

	i = *idx;
	length = 0;
	while (is_printable(buff[i++]))
		length++;
	if (length == 0 || buff[i - 1] != '\n')
		return (0);
	val = (char *)malloc(sizeof(char) * (length + 1));
	if (val == 0)
		return (0);
	k = 0;
	while (is_printable(buff[*idx]))
	{
		val[k++] = buff[*idx];
		*idx += 1;
	}
	val[k + 1] = '\n';
	return (val);
}
