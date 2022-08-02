/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:23:32 by wonyang           #+#    #+#             */
/*   Updated: 2022/08/02 09:11:22 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_info(t_info *info, va_list ap)
{
	int	total_size;

	total_size = 0;
	if (info->type == '%')
		total_size += print_info_persent(info);
	else if (info->type == 'd' || info->type == 'i')
		total_size += print_info_di(info, ap);
	else if (info->type == 'u')
		total_size += print_info_u(info, ap);
	else if (info->type == 'c')
		total_size += print_info_c(info, ap);
	else if (info->type == 's')
		total_size += print_info_s(info, ap);
	else if (info->type == 'x' || info->type == 'X')
		total_size += print_info_xx(info, ap);
	else
		total_size += print_info_p(info, ap);
	return (total_size);
}

char	*update_flagwidth(char *format, t_info *info)
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
	return (format);
}

char	*update_precispeci(char *format, t_info *info)
{
	if (*format == '.')
	{
		info->period = TRUE;
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
	int		total_size;

	total_size = 0;
	while (*format)
	{
		info = new_info();
		while (*format && *format != '%')
		{
			write(1, format, 1);
			total_size++;
			format++;
		}
		if (*format)
		{
			format = update_flagwidth(format + 1, info);
			format = update_precispeci(format, info);
			total_size += print_info(info, ap);
		}
		free(info);
	}
	return (total_size);
}

int	ft_printf(const char *format, ...)
{
	int		total_size;
	va_list	ap;

	va_start(ap, format);
	total_size = parse_format((char *)format, ap);
	va_end(ap);
	return (total_size);
}
