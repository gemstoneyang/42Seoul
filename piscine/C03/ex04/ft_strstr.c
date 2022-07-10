/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:38:10 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/24 09:57:18 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_string(char *str, char *to_find, int index)
{
	int	i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (str[index + i] == '\0' || str[index + i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (check_string(str, to_find, i) == 1)
			return (&str[i]);
		i++;
	}
	return (0);
}
