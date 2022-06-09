/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:12:37 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/09 02:56:29 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	check_duplicate(char buffer[4096], int idx)
{
	int				charset[256];
	int				i;
	unsigned char	c;

	i = 0;
	while (i < 256)
	{
		charset[i] = 0;
		i++;
	}
	i = idx - 1;
	while (i >= idx - 3)
	{
		c = (unsigned char)buffer[i];
		if (!(' ' <= c && c <= '~'))
			return (ERROR);
		if (!charset[c])
			charset[c] = 1;
		else
			return (ERROR);
		i--;
	}
	return (0);
}

int	validation_charset(char buffer[4096], int idx)
{
	int				i;
	unsigned char	c;

	if (idx < 4 || check_duplicate(buffer, idx) == ERROR)
		return (ERROR);
	i = idx - 4;
	while (i >= 0)
	{
		c = (unsigned char)buffer[i];
		if (!('0' <= c && c <= '9'))
			return (ERROR);
		i--;
	}
	return (0);
}

int	read_info(t_info *map_info, char buffer[4096], int len)
{
	int	i;
	int	info_len;

	info_len = 0;
	while (info_len < len && buffer[info_len] != '\n')
		info_len++;
	if (info_len == len || validation_charset(buffer, info_len))
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		map_info->charset[2 - i] = buffer[info_len - i - 1];
		i++;
	}
	if (info_len - i >= 10)
		return (ERROR);
	buffer[info_len - i] = ':';
	map_info->x = ft_atoi(buffer);
	return (info_len);
}

int	count_map_length(char buffer[4096], char *file_path, int info_len)
{
	int	rfd;
	int	count;
	int	i;
	int	len;

	rfd = open(file_path, O_RDONLY);
	if (rfd == ERROR)
		return (ERROR);
	read(rfd, buffer, info_len + 1);
	count = 0;
	while (1)
	{
		i = 0;
		len = read(rfd, buffer, 4096);
		if (len == ERROR)
			return (ERROR);
		while (buffer[i] != '\n' && i < len)
			i++;
		count += i;
		if (len == 0 || buffer[i] == '\n')
			break ;
	}
	if (close(rfd) == ERROR)
		return (ERROR);
	return (count);
}

int	search_info_line(t_info *map_info, char *file_path)
{
	char	buffer[4096];
	int		rfd;
	int		len;
	int		info_len;

	rfd = open(file_path, O_RDONLY);
	if (rfd == ERROR)
		return (ERROR);
	len = read(rfd, buffer, 4096);
	if (len == ERROR)
		return (ERROR);
	if (close(rfd) == ERROR)
		return (ERROR);
	info_len = read_info(map_info, buffer, len);
	map_info->y = count_map_length(buffer, file_path, info_len);
	if (map_info->y == ERROR || map_info->y == 0)
		return (ERROR);
	return (info_len);
}
