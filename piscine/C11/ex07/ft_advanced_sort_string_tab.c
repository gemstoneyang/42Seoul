/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:50:50 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/06 16:50:53 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap1(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_strlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char*))
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(tab);
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if ((*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap1(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
