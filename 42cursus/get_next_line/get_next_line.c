/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:28:01 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/18 01:15:11 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_ed_chr(char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	return (i);
}

void	free_all(char **p1, char **p2)
{
	free(*p1);
	free(*p2);
	*p1 = NULL;
	*p2 = NULL;
}

char	*get_next_line(int fd)
{
    static char	*res;
    char	*buffer;
    char    	*tmp;
    char    	*value;
    ssize_t 	size;
    char	*sub_str;
    
    if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
	return (NULL);
    while (1)
    {
	if (!res)
	{
	    res = (char *)ft_calloc(1, sizeof(char));
	    if (!res)
		return (res);
	}
    	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    	if (!buffer)
	{
	    free(res);
	    res = NULL;
    	    return (buffer);
	}
    	size = read(fd, buffer, BUFFER_SIZE);
    	if (size == -1)
    	{
    	    free_all(&buffer, &res);
	    return (NULL);
	}
	if (size == 0)
	{
	    free(buffer);
	    buffer = NULL;
	    if (ft_strlen(res))
	    {
		value = ft_strjoin(res, "\n");
		if (!value)
		{
		    free(res);
		    res = NULL;
		    return (value);
		}
		free(res);
		res = NULL;
		return (value);
	    }
	    free(res);
	    res = NULL;
	    return (NULL);
	}
	tmp = res;
	if (size == BUFFER_SIZE)
	{
	    if (find_ed_chr(buffer) == BUFFER_SIZE)
	    {
		res = ft_strjoin(tmp, buffer);
		if (!res)
		{
		    free_all(&buffer, &tmp);
		    return (res);
		}
		free_all(&buffer, &tmp);
		continue ;
	    }
	    else
	    {
		sub_str = ft_substr(buffer, 0, find_ed_chr(buffer));
		if (!sub_str)
		{
		    free_all(&buffer, &tmp);
		    return (sub_str);
		}
	        value = ft_strjoin(tmp, sub_str);
		if (!value)
		{
		    free_all(&buffer, &tmp);
		    free(sub_str);
		    sub_str = NULL;
		    return (value);
	        }
		free_all(&tmp, &sub_str);
		res = ft_substr(buffer, find_ed_chr(buffer) + 1, BUFFER_SIZE - find_ed_chr(buffer) - 1);
		if (!res)
		{
		    free_all(&buffer, &value);
		    return (res);
		}
		free(buffer);
		buffer = NULL;
		return (value);
	    }
	}
	else
	{
	    sub_str = ft_substr(buffer, 0, size);
	    if (!sub_str)
	    {
	        free_all(&buffer, &tmp);
	        return (sub_str);
	    }
	    value = ft_strjoin(tmp, sub_str);
	    if (!value)
	    {
		free_all(&buffer, &tmp);
		free(sub_str);
		sub_str = NULL;
		return (value);
	    }
	    free_all(&tmp, &sub_str);
	    free(buffer);
	    buffer = NULL;
	    res = NULL;
	    tmp = value;
	    /*
	    value = ft_strjoin(tmp, "\n");
	    if (!value)
	    {
		free(tmp);
		tmp = NULL;
		return (value);
	    }
	    free(tmp);
	    tmp = NULL;
	    */
	    return (value);
	}
    }
    return (value);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *str = get_next_line(fd);
    printf("%s", str);
    free(str);
    str = NULL;
    for (int i = 0; i < 3; i++)
    {
	str = get_next_line(fd);
	printf("%s\n", str);
	if (str)
	{
	    free(str);
	    str = NULL;
	}
    }
    
    return (0);
}
*/
