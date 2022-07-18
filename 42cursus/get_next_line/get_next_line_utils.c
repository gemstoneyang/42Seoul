/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:23:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/18 19:21:47 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*dst;
	unsigned char	ch;
	size_t			i;

	dst = (unsigned char *)ptr;
	ch = (unsigned char)value;
	i = 0;
	while (i < len)
	{
		*dst = ch;
		dst++;
		i++;
	}
	return (ptr);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	p = malloc(num * size);
	if (!p)
		return (p);
	ft_memset(p, 0, num * size);
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = ft_strlen(dst);
	if (i >= len)
		return (ft_strlen(src) + len);
	j = 0;
	count = ft_strlen(dst) + ft_strlen(src);
	while (i < len - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(len, sizeof(char));
	if (!str)
		return (str);
	ft_strlcat(str, s1, len);
	ft_strlcat(str, s2, len);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	size_t	i;

	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)(str + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(str + i));
	else
		return (0);
}

char	*ft_strndup(const char *str, size_t len)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
	    return (s);
	i = 0;
	while (i < len)
	{
	    s[i] = str[i];
	    i++;
	}
	s[i] = '\0';
	return (s);
}
