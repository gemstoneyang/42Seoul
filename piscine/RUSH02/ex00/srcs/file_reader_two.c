/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:31:53 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:34:17 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_reader_two.h"

int	parse_buff_dict(t_dict *dict, char *buff, int *idx)
{
	char	delimiter;

	dict->next->l_space = space_field_parse(buff, idx);
	delimiter = buff[*idx];
	*idx += 1;
	dict->next->r_space = space_field_parse(buff, idx);
	dict->next->value = character_field_parse(buff, idx);
	if (dict->next->l_space == -1 || dict->next->r_space == -1 || \
			delimiter != ':' || dict->next->value == 0)
		return (0);
	return (1);
}

int	parse_buff_digit_dict(t_digit_dict *digit_dict, char *buff, int *idx)
{
	char	delimiter;

	digit_dict->next->l_space = space_field_parse(buff, idx);
	delimiter = buff[*idx];
	*idx += 1;
	digit_dict->next->r_space = space_field_parse(buff, idx);
	digit_dict->next->value = character_field_parse(buff, idx);
	if (digit_dict->next->l_space == -1 || digit_dict->next->r_space == -1 || \
			delimiter != ':' || digit_dict->next->value == 0)
		return (0);
	return (1);
}

int	parse_buff(t_dict *dict, t_digit_dict *digit_dict, char	*buff)
{
	int	struct_type;
	int	just_zero;
	int	*idx;
	int	is_ok;

	is_ok = 1;
	just_zero = 0;
	idx = &just_zero;
	struct_type = number_field_parse(dict, digit_dict, buff, idx);
	if (struct_type == 1)
		is_ok = parse_buff_dict(dict, buff, idx);
	else if (struct_type == 2)
		is_ok = parse_buff_digit_dict(digit_dict, buff, idx);
	else
		return (0);
	if (is_ok == 0)
		return (0);
	return (struct_type);
}
