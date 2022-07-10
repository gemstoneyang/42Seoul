/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:58:54 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/09 14:01:10 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = -1;
	if (d < s)
		while (++i < num)
			*d++ = *s++;
	else
		while (++i < num)
			*(d + num - i - 1) = *(s + num - i - 1);
	return (dst);
}
