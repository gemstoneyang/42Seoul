/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:35:49 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 22:05:06 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "two_argument.h"

char	*ft_strcpy(char *str)
{
	char	*new_str;
	int		size;
	int		i;

	size = 0;
	while (str[size])
		size++;
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == 0)
		return (0);
	i = -1;
	while (++i <= size)
		new_str[i] = str[i];
	return (new_str);
}

int	find_in_dict(t_dict *dict_cur, int key, char *str, int line_num)
{
	t_dict	*new_dict;

	while (dict_cur->next)
	{
		dict_cur = dict_cur->next;
		if (dict_cur->key == key)
		{
			free(dict_cur->value);
			dict_cur->value = ft_strcpy(str);
			return (1);
		}
	}
	new_dict = (t_dict *)malloc(sizeof(t_dict));
	new_dict->next = dict_cur->next;
	new_dict->key = key;
	new_dict->l_space = 0;
	new_dict->r_space = 0;
	new_dict->line_num = line_num;
	new_dict->value = ft_strcpy(str);
	dict_cur->next = new_dict;
	return (0);
}

int	find_in_digit_dict(t_digit_dict *digit_dict_cur, int digit, \
		char *str, int line_num)
{
	t_digit_dict	*new_dict;

	while (digit_dict_cur->next)
	{
		digit_dict_cur = digit_dict_cur->next;
		if (digit_dict_cur->digit == digit)
		{
			free(digit_dict_cur->value);
			digit_dict_cur->value = ft_strcpy(str);
			return (1);
		}
	}
	new_dict = (t_digit_dict *)malloc(sizeof(t_digit_dict));
	new_dict->next = digit_dict_cur->next;
	new_dict->digit = digit;
	new_dict->l_space = 0;
	new_dict->r_space = 0;
	new_dict->line_num = line_num;
	new_dict->value = ft_strcpy(str);
	digit_dict_cur->next = new_dict;
	return (0);
}

void	write_dictionary_remain(int fd, t_dict *dict_cur, \
		t_digit_dict *digit_dict_cur)
{
	while (digit_dict_cur->next)
	{
		digit_dict_cur = digit_dict_cur->next;
		write_digit_dict(fd, digit_dict_cur);
	}
	while (dict_cur->next)
	{
		dict_cur = dict_cur->next;
		write_dict(fd, dict_cur);
	}
}

int	write_dictionary(t_dict *dict_cur, t_digit_dict *digit_dict_cur)
{
	int	fd;

	fd = open("numbers.dict", O_TRUNC | O_WRONLY);
	if (0 == fd)
		return (1);
	while (dict_cur -> next && digit_dict_cur -> next)
	{
		if (dict_cur->next->line_num < digit_dict_cur->next->line_num)
		{
			dict_cur = dict_cur->next;
			write_dict(fd, dict_cur);
		}
		else
		{
			digit_dict_cur = digit_dict_cur->next;
			write_digit_dict(fd, digit_dict_cur);
		}
	}
	write_dictionary_remain(fd, dict_cur, digit_dict_cur);
	close(fd);
	return (0);
}
