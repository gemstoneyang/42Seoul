/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonyang <wonyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:23:32 by wonyang           #+#    #+#             */
/*   Updated: 2022/07/31 02:41:10 by wonyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_info(t_info *info, va_list ap)
{
	int	return_size;

	return_size = 0;
	if (info->type == '%')
		return_size += print_info_persent(info);
	else if (info->type == 'd' || info->type == 'i')
		return_size += print_info_di(info, ap);
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
		{
			format = read_format(format + 1, info);
			return_size += print_info(info, ap);
		}
		free(info);
	}
	return (return_size);
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

/** #include <limits.h> */
/**  */
/** int main(void) */
/** { */
/**     int a = printf(" %.2d \n", -1); */
/**     printf(" %.3d |\n", -11); */
/**     printf(" %.4d \n", -14); */
/**     printf(" %.5d \n", -15); */
/**     printf(" %.6d \n", -16); */
/**     printf(" %.11d \n", LONG_MAX); */
/**     printf(" %.13d \n", UINT_MAX); */
/**     printf(" %.14d \n", ULONG_MAX); */
/**     printf(" %.15d \n", 9223372036854775807LL); */
/**     printf(" %.9d %.10d %.11d %.12d %.13d %.14d %.15d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
/**     int b = ft_printf(" %.2d \n", -1); */
/**     ft_printf(" %.3d |\n", -11); */
/**     ft_printf(" %.4d \n", -14); */
/**     ft_printf(" %.5d \n", -15); */
/**     ft_printf(" %.6d \n", -16); */
/**     ft_printf(" %.11d \n", LONG_MAX); */
/**     ft_printf(" %.13d \n", UINT_MAX); */
/**     ft_printf(" %.14d \n", ULONG_MAX); */
/**     ft_printf(" %.15d \n", 9223372036854775807LL); */
/**     ft_printf(" %.9d %.10d %.11d %.12d %.13d %.14d %.15d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42); */
/**     printf("a:%d b:%d\n", a, b); */
/**     return (0); */
/** } */
