/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:22:24 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/08 23:34:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_header.h"

int	create_map(t_info map_info, char **map, char *file_path, int result)
{
	int		i;
	int		len;
	int		rfd;
	char	tmp[20];

	rfd = open(file_path, O_RDONLY);
	if (rfd == ERROR)
		return (ERROR);
	read(rfd, tmp, result + 1);
	i = 0;
	while (i < map_info.x)
	{
		len = read(rfd, map[i], map_info.y + 1);
		if (len == ERROR)
			return (ERROR);
		if (len != map_info.y + 1 || map[i][map_info.y] != '\n')
			return (ERROR);
		if (len == 0)
			break ;
		i++;
	}
	len = read(rfd, tmp, 20);
	if (len == ERROR || len > 0 || close(rfd) == ERROR)
		return (ERROR);
	return (0);
}

int	write_stdin(void)
{
	int		fd;
	int		len;
	char	buffer[4096];

	fd = open(STDINFILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ERROR);
	while (1)
	{
		len = read(0, buffer, 4096);
		if (len == -1)
			return (ERROR);
		if (len == 0)
			break ;
		write(fd, buffer, len);
	}
	return (0);
}

int	main_logic(char *file_path)
{
	int		info_len;	
	t_info	map_info;
	char	**map;
	int		**bsq;

	info_len = search_info_line(&map_info, file_path);
	if (info_len == ERROR)
		return (ERROR);
	if (init(&map, &bsq, map_info.x, map_info.y + 1))
		return (ERROR);
	if (create_map(map_info, map, file_path, info_len))
	{
		final_free(&map, &bsq, map_info.x);
		return (ERROR);
	}
	if (bsq_main(map, bsq, map_info) == ERROR)
	{
		final_free(&map, &bsq, map_info.x);
		return (ERROR);
	}
	final_free(&map, &bsq, map_info.x);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		if (write_stdin() == ERROR | main_logic(STDINFILE) == ERROR)
			write(2, "map error\n", 10);
		return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (i != 1)
				write(1, "\n", 1);
			if (main_logic(argv[i]) == ERROR)
				write(2, "map error\n", 10);
			i++;
		}
	}
	return (0);
}
