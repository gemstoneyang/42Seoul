/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:13:34 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/22 01:14:27 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *cache, char *buffer);
char	*ft_strchr(char *str, int c);

char	*ft_read_file(int fd, char *cache);
char	*ft_get_line(char *cache);
char	*ft_update_cache(char *cache);
char	*get_next_line(int fd);

#endif
