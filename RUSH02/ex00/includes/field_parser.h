/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:34:46 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:36:05 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELD_PARSER_H
# define FIELD_PARSER_H

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

int is_number(char c);
int is_printable(char c);
int is_delimiter(char c);
int is_space(char c);
int is_digit(char *c);
int is_printable(char c);
int ft_atoi(char *str);

#endif
