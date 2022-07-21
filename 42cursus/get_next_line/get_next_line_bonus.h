/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:44:29 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/21 23:46:19 by wonyang          ###   ########.fr       */
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
	char			*cache;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *cache, char *buffer);
char	*ft_strchr(char *str, int c);

void	ft_del_node(t_list **list, int fd);
t_list	*ft_find_node(t_list **list, int fd);
t_list	*ft_make_node(int fd);

char	*ft_read_file(int fd, char *cache);
char	*ft_get_line(char *cache);
char	*ft_update_cache(char *cache);
char	*get_next_line(int fd);

#endif
