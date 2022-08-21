/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:13:22 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/06 14:30:09 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *cache)
{
	char	*buffer;
	ssize_t	read_byte;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(cache, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			if (cache)
				free(cache);
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	free(buffer);
	return (cache);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	cache = ft_read_file(fd, cache);
	if (!cache)
		return (NULL);
	result = ft_get_line(cache);
	cache = ft_update_cache(cache);
	return (result);
}
