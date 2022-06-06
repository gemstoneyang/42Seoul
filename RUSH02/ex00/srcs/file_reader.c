/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:46:20 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:28:11 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_reader.h"

int	get_one_line(int fd, char *buff)
{
	int	i;
	int	fd_size;

	fd_size = 1;
	i = 0;
	while (fd_size != 0)
	{
		fd_size = read(fd, &buff[i], 1);
		if (fd_size == 0)
			return (fd_size);
		if (buff[i++] == '\n')
			break ;
		if (i == 4096)
		{
			dict_error();
			close(fd);
			return (-1);
		}
	}
	return (fd_size);
}

int	file_read_struct_type(t_dict *dict, t_digit_dict *digit_dict, \
		int line_num, int struct_type)
{
	if (struct_type == 1)
	{
		dict -> next -> line_num = line_num;
		return (0);
	}
	else if (struct_type == 2)
	{
		digit_dict -> next -> line_num = line_num;
		return (0);
	}
	else
		return (1);
}

int	file_read(t_dict *dict, t_digit_dict *digit_dict)
{
	char	buff[4096];
	int		fd;
	int		fd_size;
	int		struct_type;
	int		line_num;

	fd_size = 1;
	line_num = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd == 0)
		return (1);
	while (0 != fd_size)
	{
		fd_size = get_one_line(fd, buff);
		if (fd_size == 0)
			break ;
		struct_type = parse_buff(dict, digit_dict, buff);
		if (struct_type == 1)
			dict = dict->next;
		if (struct_type == 2)
			digit_dict = digit_dict->next;
		line_num++;
	}
	close(fd);
	return (0);
}
