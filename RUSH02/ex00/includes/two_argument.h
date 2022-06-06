/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_argument.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:35:12 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:37:30 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWO_ARGUMENT_H
# define TWO_ARGUMENT_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

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

void    write_dict(int fd, t_dict *dict);
void    write_digit_dict(int fd, t_digit_dict *digit_dict);

#endif
