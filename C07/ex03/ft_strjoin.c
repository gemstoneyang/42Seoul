/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:10:11 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/01 16:42:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	total_len(char **strs, int size, char *sep)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			total++;
			j++;
		}
		if (i != size - 1)
		{
			j = -1;
			while (sep[++j] != '\0')
			{
				total++;
			}
		}
	}
	return (total);
}

char	*make_array(int size, char **strs, char *sep)
{
	char	*result;
	int		len;
	int		i;

	len = total_len(strs, size, sep);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (result);
	i = 0;
	while (i < len + 1)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		res_count;
	char	*result;

	result = make_array(size, strs, sep);
	i = -1;
	res_count = 0;
	while (++i < size)
	{
		result = ft_strcat(result, strs[i]);
		if (i != size - 1)
			result = ft_strcat(result, sep);
	}
	return (result);
}
