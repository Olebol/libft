/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 22:04:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/09 21:26:14 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list				va_ptr;
	int					i;
	int					count;
	const t_function	jump_table[126] = {
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

	va_start(va_ptr, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += jump_table[(int)format[i + 1]](va_ptr);
			i += 2;
			continue ;
		}
		write(1, &format[i], 1);
		count++;
		i++;
	}
	va_end(va_ptr);
	return (count);
}

int		main(void)
{
	char	c = 'X';
	// char	*s = "XXXX";
	char	*p = "pointer test";
	int		d = -78901;
	unsigned int u = 198296479;
	int		x = 123456789;

	int		ret;

	ret = ft_printf("my printf:\n\nchar: %c\nstr: %s\nptr: %p\n", c, NULL, p);
	ret += ft_printf("dec: %d\nuns: %u\nhex: %x\nhexup: %X\n\t%%", d, u, x, x);
	printf("\n\nreturn: %d\n", ret);
	ret = printf("\n\nprintf:\n\nchar: %c\nstr: %s\nptr: %p\n", c, NULL, p);
	ret += printf("dec: %d\nuns: %u\nhex: %x\nhexup: %X\n\t%%", d, u, x, x);
	printf("\n\nreturn: %d\n", ret);
	return (0);
}
