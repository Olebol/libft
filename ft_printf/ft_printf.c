/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 22:04:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/10 17:54:47 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdarg.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	jumptable(const char *format, int specifier, va_list va_ptr)
{
	int					count;
	static const char	format_specifiers[10] = "cspdiuxX%";
	static t_function	function_array[126] = {
	['c'] = ft_printf_c,
	['s'] = ft_printf_s,
	['p'] = ft_printf_p,
	['d'] = ft_printf_di,
	['i'] = ft_printf_di,
	['u'] = ft_printf_u,
	['x'] = ft_printf_hex,
	['X'] = ft_printf_hexup,
	['%'] = ft_printf_percent,
	};

	if (!ft_strrchr(format_specifiers, format[specifier]))
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		if (write(1, &format[specifier], 1) == -1)
			return (-1);
		return (2);
	}
	count = function_array[(unsigned char) format[specifier]](va_ptr);
	return (count);
}

int	ft_printed_length(const char *format, va_list va_ptr)
{
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				if ((write(1, "%", 1)) == -1)
					return (-1);
				i++;
				count++;
				return (count);
			}
			tmp = jumptable(format, (i + 1), va_ptr);
			if (tmp < 0)
				return (-1);
			count += tmp;
			i += 2;
			continue ;
		}
		if (write(1, &format[i], 1) == -1)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		va_ptr;
	int			count;

	va_start(va_ptr, format);
	count = ft_printed_length(format, va_ptr);
	va_end(va_ptr);
	return (count);
}

// int		main(void)
// {
// 	char	c = 'X';
// 	char	*s = "XXXX";
// 	char	*p = "pointer test";
// 	int		d = -78901;
// 	unsigned int u = 198296479;
// 	int		x = 123456789;

// 	int		ret;

// 	ret = ft_printf("my printf:\n\nchar: %c\nstr: %s\nptr: %p\n", c, s, p);
// 	ret += ft_printf("dec: %d\nuns: %u\nhex: %x\nhexup: %X\n", d, u, x, x);
// 	ret += ft_printf("percent edge cases: | %%%rabc | %%% | %");
// 	printf("\n\nreturn: %d\n\n| --------------------------- |", ret);

// 	ret = printf("\n\nprintf:\n\nchar: %c\nstr: %s\nptr: %p\n", c, s, p);
// 	ret += printf("dec: %d\nuns: %u\nhex: %x\nhexup: %X\n", d, u, x, x);
// 	ret += printf("percent edge cases: | %%%rabc | %%% | %");
// 	printf("\n\nreturn: %d\n", ret);
// 	return (0);
// }
