/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:34:56 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:36:24 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READER_H
# define FILE_READER_H

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

int parse_buff(t_dict *dict, t_digit_dict *digit_dict, char *buff);
void    dict_error(void);

#endif
