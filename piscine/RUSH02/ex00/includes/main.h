/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:35:04 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:36:56 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
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

void    print_dictionary(t_dict *dict_head, t_digit_dict *digit_dict_head);
void    convert_string(char *string, t_dict *t_head, t_digit_dict *t_digit_head);
int two_argument(t_dict *dict_head, t_digit_dict *digit_dict_head, char *key, char *new_string);
int one_argument(char *key, t_dict *t_head, t_digit_dict *t_digit_head);
int write_dictionary(t_dict *dict_cur, t_digit_dict *digit_dict_cur);
int find_in_dict(t_dict *dict_cur, int key, char *str, int line_num);
int find_in_digit_dict(t_digit_dict *digit_dict_cur, int digit, char *str, int line_num);
void    free_all(t_dict *dict, t_digit_dict *digit_dict);
int file_read(t_dict *dict, t_digit_dict *digit_dict);
int ft_atoi(char *c);
int is_digit(char *c);
int is_number(char c);
void    not_valid_argc_error();

#endif
