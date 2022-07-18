/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:28:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/18 23:06:12 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_all(char **p1, char **p2)
{
	free(*p1);
	free(*p2);
	*p1 = NULL;
	*p2 = NULL;
}

int make_new_line(char **cache, char **buffer, char **result)
{
    char    *nxt_chr;
    char    *tmp;

    if (ft_strlen(*buffer) == 0)
    {
	if (ft_strlen(*cache) == 0)
	{
	    free_all(buffer, cache);
	    return (0);
	}
	*result = ft_strndup(*cache, ft_strlen(*cache));
	free_all(buffer, cache);
	return (1);
    }
    nxt_chr = ft_strchr(*buffer, '\n');
    if (nxt_chr == NULL)
    {
	tmp = *cache;
	*cache = ft_strjoin(tmp, *buffer);
	free_all(&tmp, buffer);
	return (0);
    }
    tmp = ft_strndup(*buffer, nxt_chr - *buffer + 1);
    *result = ft_strjoin(*cache, tmp);
    free_all(cache, &tmp);
    *cache = ft_strndup(nxt_chr + 1, ft_strlen(nxt_chr + 1));
    free(*buffer);
    return (1);
}

char	*get_next_line(int fd)
{
    static char	*cache;
    char	*buffer;
    char	*result;
    size_t	read_size;

    if (cache && ft_strchr(cache, '\n'))
    {
	buffer = cache;
	cache = (char *)ft_calloc(1, sizeof(char));
	make_new_line(&cache, &buffer, &result);
	return (result);
    }
    while (1)
    {
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE < 1)
	{
	    free(buffer);
	    return (NULL);
	}
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (cache == NULL)
	    cache = (char *)ft_calloc(1, sizeof(char));
	if (read_size < BUFFER_SIZE)
	{
	    buffer[read_size] = '\0';
	    if (make_new_line(&cache, &buffer, &result) == 0)
	    {
		result = cache;
		cache = NULL;
		return (result);
	    }
	    return (result);
	}
	if (make_new_line(&cache, &buffer, &result) == 0)
	    continue;
	return (result);
    }
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *str;
    for (int i = 0; i < 6; i++)
    {
	str = get_next_line(fd);
	printf("%s", str);
	if (str)
	{
	    free(str);
	    str = NULL;
	}
    }
    
    return (0);
}
*/
