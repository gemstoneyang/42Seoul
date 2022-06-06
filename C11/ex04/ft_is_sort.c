/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:41:43 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/06 01:52:01 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	return_key(int val)
{
	if (val < 0)
		return (-1);
	else if (val > 0)
		return (1);
	else
		return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	key;
	int	check;

	if (length < 2)
		return (1);
	i = 0;
	key = 0;
	while (i < length - 1)
	{
		check = return_key((*f)(tab[i], tab[i + 1]));
		if (key == 0 && check != 0)
			key = check;
		else if (check != 0 && key != check)
			return (0);
		i++;
	}
	return (1);
}
