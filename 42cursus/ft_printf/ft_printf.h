/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:25:12 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 16:54:29 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef int	t_bool;

typedef struct s_info
{
	char			type;
	t_bool			minus;
	t_bool			plus;
	t_bool			space;
	t_bool			zero;
	t_bool			hash;
	t_bool			period;
	int				width;
	int				precision;
}					t_info;

# define TRUE 1
# define FALSE 0

t_bool	ft_isflag(char c);
t_bool	ft_isspecifier(char c);

t_info	*new_info(void);

int		print_persent_blank(t_info *info);
int		print_info_persent(t_info *info);

int		ft_absnumlen(t_info *info, int num);
int		ft_blank_size(t_info *info, int num_len, int val_int);

int		print_di_sign(t_info *info, int val_int);
int		print_di_num(t_info *info, int val_int);
int		print_di_space(t_info *info, int val_int);
int		print_di_zero(t_info *info, int val_int);
int		print_info_di(t_info *info, va_list ap);

void	update_info_flag(char flag, t_info *info);
void	update_info_width(char n, t_info *info);
void	update_info_precision(char n, t_info *info);

char	*read_format(char *format, t_info *info);

int		print_info(t_info *info, va_list ap);
int		parse_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
