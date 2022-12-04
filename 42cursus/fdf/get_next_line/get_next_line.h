/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:13:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/12/04 13:03:10 by wonyang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define SUCCESS 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>

size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *cache, char *buffer);
char	*gnl_strchr(char *str, int c);
ssize_t	gnl_free_all(char *cache, char *result);

ssize_t	get_next_line(char **result, int fd);

#endif
