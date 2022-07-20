/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:17:38 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/20 18:47:40 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*value;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_strndup(const char *str, size_t len);

void	del_node(t_list **cache, int fd);
t_list	*find_node(t_list **cache, int fd);
char	*low_read(t_list **cache, char buffer[], int fd);
char	*make_new_line_sub(t_list **cache, char buffer[], char *nxt_chr, int fd);
int		make_new_line(t_list **cache, char buffer[], char **result, int fd);
char	*get_next_line(int fd);

#endif
