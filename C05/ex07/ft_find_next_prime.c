/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:28:04 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/30 10:55:44 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	res;
	int	is_prime;

	if (nb <= 1)
		return (2);
	res = 2;
	i = 2;
	while (1)
	{
		is_prime = 1;
		i = 2;
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{	
				is_prime = 0;
				break ;
			}
			i++;
		}
		if (is_prime)
			return (nb);
		nb++;
	}
}
