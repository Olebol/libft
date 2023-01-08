/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 22:04:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/08 22:13:54 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list			ptr;
	int				i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			write(1, "[ % ]", 6);
			i += 2;
			continue ;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_start(ptr, format);

	va_end(ptr);
	return (0);
}

int		main(void)
{
	ft_printf("abc%sde\\f");
	return (0);
}

/*
%c: This specifier is used to print a single character.
%s: This specifier is used to print a string of characters.
%p: This specifier is used to print a pointer value.
%d: This specifier is used to print a signed integer in decimal format.
%i: This specifier is also used to print a signed integer, but in decimal, octal, or hexadecimal format, depending on the value of the integer and the format flags specified.
%u: This specifier is used to print an unsigned integer in decimal format.
%x: This specifier is used to print an unsigned integer in hexadecimal format, using lowercase letters for the digits a through f.
%X: This specifier is used to print an unsigned integer in hexadecimal format, using uppercase letters for the digits A through F.
%%: This specifier is used to print a percent sign.
*/