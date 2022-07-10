/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:21:50 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:31:03 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_dict			*dict_head;
	t_dict			*dict_cur_head;
	t_digit_dict	*digit_dict_head;
	t_digit_dict	*digit_dict_cur_head;

	dict_head = (t_dict *)malloc(sizeof(t_dict));
	digit_dict_head = (t_digit_dict *)malloc(sizeof(t_digit_dict));
	dict_cur_head = dict_head;
	digit_dict_cur_head = digit_dict_head;
	file_read(dict_cur_head, digit_dict_cur_head);
	if (argc == 2)
		one_argument(argv[1], dict_head, digit_dict_head);
	else if (argc == 3)
		two_argument(dict_head, digit_dict_head, argv[1], argv[2]);
	else
		not_valid_argc_error();
	free_all(dict_head, digit_dict_head);
}

int	one_argument(char *key, t_dict *t_head, t_digit_dict *t_digit_head)
{
	int	i;

	i = 0;
	convert_string(key, t_head, t_digit_head);
	return (0);
}

int	get_line_num(t_dict *dict_head, t_digit_dict *digit_dict_head)
{
	int				max_line_num;
	t_dict			*temp;
	t_digit_dict	*digit_temp;

	max_line_num = 0;
	temp = dict_head;
	digit_temp = digit_dict_head;
	while (temp -> next)
	{
		temp = temp -> next;
		if (max_line_num < temp->line_num)
			max_line_num = temp->line_num;
	}
	while (digit_temp -> next)
	{
		digit_temp = digit_temp -> next;
		if (max_line_num < digit_temp->line_num)
			max_line_num = digit_temp->line_num;
	}
	return (max_line_num + 1);
}

int	two_argument(t_dict *dict_head, t_digit_dict *digit_dict_head, \
		char *key, char *new_string)
{
	int	line_num;
	int	num;

	line_num = get_line_num(dict_head, digit_dict_head);
	if (is_digit(key))
	{
		num = 0;
		while (key[num])
			num++;
		find_in_digit_dict(digit_dict_head, num, new_string, line_num);
	}
	else
	{
		num = ft_atoi(key);
		find_in_dict(dict_head, num, new_string, line_num);
	}
	write_dictionary(dict_head, digit_dict_head);
	return (0);
}

void	free_all(t_dict *dict, t_digit_dict *digit_dict)
{
	t_dict			*temp_dict;
	t_digit_dict	*temp_digit_dict;

	while (dict->next)
	{
		temp_dict = dict->next;
		dict->next = temp_dict->next;
		free(temp_dict->value);
		free(temp_dict);
	}
	while (digit_dict->next)
	{
		temp_digit_dict = digit_dict->next;
		digit_dict->next = temp_digit_dict->next;
		free(temp_digit_dict->value);
		free(temp_digit_dict);
	}
	free(dict);
	free(digit_dict);
}
