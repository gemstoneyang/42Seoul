/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:28:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/19 03:23:02 by wonyang          ###   ########.fr       */
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

int make_new_line(char **cache, char buffer[BUFFER_SIZE + 1], char **result)
{
    char    *nxt_chr;
    char    *tmp;

    if (*cache == NULL)
	*cache = (char *)ft_calloc(1, sizeof(char));
    if (ft_strlen(buffer) == 0)
    {
	if (ft_strlen(*cache) == 0)
	{
	    free(*cache);
	    *cache = NULL;
	    return (0);
	}
	*result = ft_strndup(*cache, ft_strlen(*cache));
	free(*cache);
	*cache = NULL;
	return (1);
    }
    nxt_chr = ft_strchr(buffer, '\n');
    if (nxt_chr == NULL)
    {
	tmp = *cache;
	*cache = ft_strjoin(tmp, buffer);
	free(tmp);
	return (0);
    }
    tmp = ft_strndup(buffer, nxt_chr - buffer + 1);
    *result = ft_strjoin(*cache, tmp);
    free_all(cache, &tmp);
    *cache = ft_strndup(nxt_chr + 1, ft_strlen(nxt_chr + 1));
    return (1);
}

char	*get_next_line(int fd)
{
    static char	*cache;
    char	buffer[BUFFER_SIZE + 1];
    char	*result;
    size_t	read_size;

    if (cache && ft_strchr(cache, '\n'))
    {
	buffer[0] = '\0';
	ft_strlcat(buffer, cache, ft_strlen(cache) + 1);
	free(cache);
	cache = NULL;
	make_new_line(&cache, buffer, &result);
	return (result);
    }
    while (1)
    {
	if (read(fd, buffer, 0) == -1 || BUFFER_SIZE < 1)
	    return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	buffer[read_size] = '\0';
	if (read_size < BUFFER_SIZE)
	{
	    if (make_new_line(&cache, buffer, &result) == 0)
	    {
		result = cache;
		cache = NULL;
		return (result);
	    }
	    return (result);
	}
	if (make_new_line(&cache, buffer, &result) == 0)
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
