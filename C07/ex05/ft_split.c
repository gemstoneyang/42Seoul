/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:32 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/01 16:44:49 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_split(int *split, char *charset)
{
	int	i;

	i = 0;
	while (i < 256)
	{
		split[i] = 0;
		i++;
	}
	i = 0;
	while (charset[i] != '\0')
	{
		split[(unsigned char)charset[i]] = 1;
		i++;
	}
}

char	*make_string(char *str, int start, int end)
{
	int		i;
	char	*result;

	i = 0;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	while (i + start < end)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**count_word(char *str, int *split)
{
	int		i;
	int		count;
	char	**result;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (split[(unsigned char)str[i]])
			i++;
		if (!split[(unsigned char)str[i]] && str[i] != '\0')
			count++;
		while (!split[(unsigned char)str[i]] && str[i] != '\0')
			i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	result[count] = 0;
	return (result);
}

int	skip_split(char *str, int *split, int start)
{
	int	i;

	i = start;
	while (split[(unsigned char)str[i]])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		split[256];
	char	**result;
	int		i_st_cnt[3];

	init_split(split, charset);
	result = count_word(str, split);
	i_st_cnt[0] = skip_split(str, split, 0);
	i_st_cnt[1] = i_st_cnt[0];
	i_st_cnt[2] = 0;
	while (str[i_st_cnt[0]])
	{
		if (split[(unsigned char)str[i_st_cnt[0]]])
		{
			result[i_st_cnt[2]] = make_string(str, i_st_cnt[1], i_st_cnt[0]);
			i_st_cnt[2]++;
			i_st_cnt[0] = skip_split(str, split, i_st_cnt[0]);
			i_st_cnt[1] = i_st_cnt[0];
			continue ;
		}
		i_st_cnt[0]++;
	}
	if (str[i_st_cnt[1]] != '\0')
		result[i_st_cnt[2]] = make_string(str, i_st_cnt[1], i_st_cnt[0]);
	return (result);
}
