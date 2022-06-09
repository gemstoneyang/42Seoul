/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 23:33:50 by wonyang           #+#    #+#             */
/*   Updated: 2022/06/08 23:40:15 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_HEADER_H
# define BSQ_HEADER_H

# define ERROR -1
# define STDINFILE "stdin_dedicated_file"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	int		x;
	int		y;
	char	charset[3];
}			t_info;

int		ft_atoi(char *str);
int		min(int a, int b, int c);
void	change_cor(int cor[3], int x, int y, int max_bsq);
int		init_bsq(char **map, int **bsq, t_info map_info, int cor[3]);
void	fill_bsq(int **bsq, t_info map_info, int cor[3]);
void	print_result(char **map, int cor[3], t_info map_info);
int		bsq_main(char **map, int **bsq, t_info map_info);
void	**array_gen(int x, int y, unsigned long p_size, unsigned long size);
void	free_multi_array(void ***array, int x);
void	final_free(char ***map, int ***bsq, int x);
int		init(char ***map, int ***bsq, int x, int y);
int		check_duplicate(char buffer[4096], int idx);
int		validation_charset(char buffer[4096], int idx);
int		read_info(t_info *map_info, char buffer[4096], int len);
int		search_info_line(t_info *map_info, char *file_path);
int		count_map_length(char buffer[4096], char *file_path, int info_len);
int		create_map(t_info map_info, char **map, char *file_path, int result);
int		write_stdin(void);
int		main_logic(char *file_path);

#endif
