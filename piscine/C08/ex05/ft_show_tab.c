/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:14:56 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/02 11:49:58 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_print_int(int n)
{
	char	*nums;

	nums = "0123456789";
	if (n / 10 == 0)
	{
		write(1, &nums[n % 10], 1);
		return ;
	}
	ft_print_int(n / 10);
	write(1, &nums[n % 10], 1);
}

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_print_str(par[i].str);
		write(1, "\n", 1);
		ft_print_int(par[i].size);
		write(1, "\n", 1);
		ft_print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
