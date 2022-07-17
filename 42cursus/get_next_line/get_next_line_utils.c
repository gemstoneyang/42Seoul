/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:23:05 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/17 23:09:27 by wonyang          ###   ########.fr       */
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

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(src);
	if (len == 0)
		return (count);
	while (src[i] && i < len - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (str_len >= len + start)
		res = (char *)ft_calloc(len + 1, sizeof(char));
	else
		res = (char *)ft_calloc(str_len - start + 1, sizeof(char));
	if (!res)
		return (res);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

