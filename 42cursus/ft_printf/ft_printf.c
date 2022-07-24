/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:23:32 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/24 22:49:21 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_info(t_info *info, va_list ap)
{
	int	return_size;

	ap = NULL;
	return_size = 0;
	if (info->type == '%')
		return_size += print_info_persent();
	return (return_size);
}

char	*read_format(char *format, t_info *info)
{
	while (ft_isflag(*format))
	{
		update_info_flag(*format, info);
		format++;
	}
	while (ft_isdigit(*format))
	{
		update_info_width(*format, info);
		format++;
	}
	if (*format == '.')
	{
		info->period = True;
		format++;
		while (ft_isdigit(*format))
		{
			update_info_precision(*format, info);
			format++;
		}
	}
	if (ft_isspecifier(*format))
	{
		info->type = *format;
		format++;
	}
	return (format);
}

int	parse_format(char *format, va_list ap)
{
	t_info	*info;
	int		return_size;

	ap = NULL;
	return_size = 0;
	while (*format)
	{
		info = new_info();
		while (*format && *format != '%')
		{
			write(1, format, 1);
			return_size++;
			format++;
		}
		if (*format)
			format = read_format(format + 1, info);
		free(info);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		return_size;
	va_list	ap;

	va_start(ap, format);
	return_size = parse_format((char *)format, ap);
	va_end(ap);
	return (return_size);
}

int main(void)
{
	ft_printf("%%");
	return (0);
}
