/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:18:20 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/22 01:20:22 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *cache, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(ft_strlen(cache) + ft_strlen(buffer) + 1);
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

char	*ft_strchr(char *str, int c)
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

char	*ft_get_line(char *cache)
{
	int		i;
	char	*str;

	i = 0;
	if (!cache[i])
		return (NULL);
	while (cache[i] && cache[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		str[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
	{
		str[i] = cache[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_update_cache(char *cache)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (!cache[i] || !cache[i + 1])
	{
		free(cache);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(cache) - i + 1) * sizeof(char));
	if (!str)
	{
		free(cache);
		return (NULL);
	}
	i++;
	j = 0;
	while (cache[i])
		str[j++] = cache[i++];
	str[j] = '\0';
	free(cache);
	return (str);
}
