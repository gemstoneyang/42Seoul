/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 00:17:37 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/02 02:30:50 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!res)
		return (res);
	i = 0;
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

t_stock_str	convert_string(char *str)
{
	t_stock_str	stock;

	stock.size = ft_strlen(str);
	stock.str = str;
	stock.copy = ft_strdup(str);
	return (stock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stocks;
	t_stock_str	final_stock;

	stocks = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stocks)
		return (stocks);
	i = 0;
	while (i < ac)
	{
		stocks[i] = convert_string(av[i]);
		i++;
	}
	final_stock.str = 0;
	stocks[i] = final_stock;
	return (stocks);
}
