/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:46 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/13 00:44:11 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (str_len >= len + start)
		res = (char *)malloc((len + 1) * sizeof(char));
	else
		res = (char *)malloc((str_len - start + 1) * sizeof(char));
	if (!res)
		return (res);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
