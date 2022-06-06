/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:18:00 by wonyang           #+#    #+#             */
/*   Updated: 2022/05/22 20:33:41 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	change_upper(char *ch)
{
	if ('a' <= *ch && *ch <= 'z')
		*ch -= 'a' - 'A';
}

void	change_down(char *ch)
{
	if ('A' <= *ch && *ch <= 'Z')
		*ch += 'a' - 'A';
}

int	check_exception(char c)
{
	if (!(('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')))
	{
		if (!('0' <= c && c <= '9'))
			return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		is_first;

	i = 0;
	is_first = 1;
	while (str[i] != '\0')
	{
		if (check_exception(str[i]) == 1)
		{
			is_first = 1;
			i++;
			continue ;
		}
		if (is_first == 1)
		{
			change_upper(&str[i]);
			is_first = 0;
		}
		else
			change_down(&str[i]);
		i++;
	}
	return (str);
}
