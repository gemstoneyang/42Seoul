/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader_two.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhkim <yunhkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:35:00 by yunhkim           #+#    #+#             */
/*   Updated: 2022/06/05 23:36:41 by yunhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_READER_TWO_H

# define FILE_READER_TWO_H

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

int number_field_parse(t_dict *dict, t_digit_dict *digit_dict, char *buff, int *idx);
char	*character_field_parse(char *buff, int *idx);
int	space_field_parse(char *buff, int *idx);

#endif
