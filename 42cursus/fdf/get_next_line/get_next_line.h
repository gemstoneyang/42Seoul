/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:13:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/09/04 17:24:01 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SUCCESS 0
# define ERROR -1

# include <unistd.h>
# include <stdlib.h>

size_t	gnl_strlen(char *str);
char	*gnl_strjoin(char *cache, char *buffer);
char	*gnl_strchr(char *str, int c);
ssize_t	free_all(char *cache, char *result);

ssize_t	get_next_line(char **result, int fd);

#endif
