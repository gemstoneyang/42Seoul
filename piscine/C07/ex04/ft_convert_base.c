/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:20:29 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/02 01:50:08 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_length(char *str, int mode);
char	*ft_putnbr_base(int nbr, char *base);
int		base_to_int(int res, char c, char *base);
void	print_base(long long n, char *base, long long len, char *result);
int		count_nbr(long long nbr, int n);
int		base_to_int(int res, char c, char *base);

int	is_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
			return (1);
		i++;
	}
	return (0);
}

int	check_same_char(char c, char *arr)
{
	int	i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] == c)
			return (1);
		i++;
	}
	arr[i] = c;
	return (0);
}

int	is_exception(char *base)
{
	int		i;
	char	arr[300];

	i = 0;
	while (i < 300)
	{
		arr[i] = '\0';
		i++;
	}
	if (count_length(base, 1) <= 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if (check_same_char(base[i], arr) == 1)
			return (1);
		i++;
	}
	if (is_blank(base))
		return (1);
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	if (is_exception(base_from) || is_exception(base_to))
		return (0);
	i = count_length(nbr, 0);
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] != '\0' && base_to_int(num, nbr[i], base_from) != -1)
	{
		num = base_to_int(num, nbr[i], base_from);
		i++;
	}
	return (ft_putnbr_base(sign * num, base_to));
}
