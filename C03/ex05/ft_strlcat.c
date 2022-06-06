/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:57:00 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/24 10:15:52 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	word_count(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;
	int				j;

	i = word_count(dest);
	if ((unsigned int)i >= size)
		return (word_count(src) + size);
	j = 0;
	count = word_count(dest) + word_count(src);
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (count);
}
