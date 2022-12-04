/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:21:04 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 13:03:17 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *cache, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(gnl_strlen(cache) + gnl_strlen(buffer) + 1);
	if (!str)
	{
		if (cache)
			free(cache);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (cache && cache[i])
	{
		str[i] = cache[i];
		i++;
	}
	while (buffer[j])
		str[i++] = buffer[j++];
	str[i] = '\0';
	if (cache)
		free(cache);
	return (str);
}

char	*gnl_strchr(char *str, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}

ssize_t	gnl_free_all(char *cache, char *result)
{
	if (cache)
		free(cache);
	if (result)
		free(result);
	return (ERROR);
}
