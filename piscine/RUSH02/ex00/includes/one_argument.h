/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_argument.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:35:06 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:37:14 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONE_ARGUMENT_H
# define ONE_ARGUMENT_H

#include <unistd.h>

typedef struct s_dict{
	int	key;
	int	l_space;
	int	r_space;
	int	line_num;
	char	*value;
	struct s_dict	*next;
} t_dict;

typedef struct s_digit_dict{
	int	digit;
	int	l_space;
	int	r_space;
	int	line_num;
	char	*value;
	struct s_digit_dict	*next;
} t_digit_dict;

#endif
