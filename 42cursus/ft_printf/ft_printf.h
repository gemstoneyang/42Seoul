/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:25:12 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/23 18:48:35 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef int t_bool;

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
}				t_info;

#define True 1
#define False 0

t_bool ft_isflag(char c);
t_bool ft_isspecifier(char c);

t_info	*new_info(void);

void	update_info_flag(char flag, t_info *info);
void	update_info_width(char n, t_info *info);
void	update_info_precision(char n, t_info *info);

char	*read_format(char *format, t_info *info);

int		parse_format(char *format, va_list ap);
int		ft_printf(const char *format, ...);

#endif
