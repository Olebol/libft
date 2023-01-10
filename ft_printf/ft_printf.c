/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 22:04:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/10 19:56:44 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...);
static int		ft_parse(const char *format, va_list va_ptr);
static int		jumptable(const char *format, int specifier, va_list va_ptr);
static int		percent_at_end(int count);
static int		ft_strrchr(const char *s, int c);

int	ft_printf(const char *format, ...)
{
	va_list		va_ptr;
	int			count;

	va_start(va_ptr, format);
	count = ft_parse(format, va_ptr);
	va_end(va_ptr);
	return (count);
}

static int	ft_parse(const char *format, va_list va_ptr)
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
				return (percent_at_end(count));
			tmp = jumptable(format, (i + 1), va_ptr);
			if (tmp == -1)
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

static int	jumptable(const char *format, int specifier, va_list va_ptr)
{
	int					count;
	int					searched;
	static t_function	function_array[9] = {
	[0] = ft_printf_c,
	[1] = ft_printf_s,
	[2] = ft_printf_p,
	[3] = ft_printf_di,
	[4] = ft_printf_di,
	[5] = ft_printf_u,
	[6] = ft_printf_hex,
	[7] = ft_printf_hexup,
	[8] = ft_printf_percent,
	};

	searched = ft_strrchr("cspdiuxX%", format[specifier]);
	if (searched < 0)
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		if (write(1, &format[specifier], 1) == -1)
			return (-1);
		return (2);
	}
	count = function_array[searched](va_ptr);
	return (count);
}

static int	percent_at_end(int count)
{
	if ((write(1, "%", 1)) == -1)
		return (-1);
	return (count + 1);
}

static int	ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (i);
		i++;
	}
	return (-1);
}

// #include <stdio.h>
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
// 	ret += ft_printf("percent edge cases: | %%%rabc | %%% | %\0don't see this");

// 	printf("\n\nreturn: %d\n\n| --------------------------- |", ret);

// 	ret = printf("\n\nprintf:\n\nchar: %c\nstr: %s\nptr: %p\n", c, s, p);
// 	ret += printf("dec: %d\nuns: %u\nhex: %x\nhexup: %X\n", d, u, x, x);
// 	// ret += printf("percent edge cases: | %%%rabc | %%% | %\0don't see this");

// 	printf("\n\nreturn: %d\n", ret);
// 	return (0);
// }
