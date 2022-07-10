/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:33:14 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 22:39:11 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	dict_error(void)
{
	write(2, "Dict Error\n", 10);
}

void	not_valid_argc_error(void)
{
	write(2, "Error\n", 6);
}
