/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 03:22:52 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/19 02:58:30 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	*ft_memset(void *ptr, int value, size_t len);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, size_t len);
void	free_all(char **p1, char **p2);
int	make_new_line(char **cache, char buffer[BUFFER_SIZE + 1], char **result);
char	*get_next_line(int fd);

#endif
