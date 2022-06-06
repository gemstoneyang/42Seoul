/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:47:10 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/20 20:16:17 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swapa(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		swapa(&tab[i], &tab[size - i -1]);
		i++;
	}
}
