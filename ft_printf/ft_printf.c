/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 22:04:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/06 17:03:01 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// parse through the format string to see how many % conversions to make
// put all the conversions into a variable
// put all the special \\ characters in a table/function
// print the variable

#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...)
{
	va_list		ptr;
	printf("%s\n", format);
	va_start(ptr, format);
	printf("%c\n", va_arg(ptr, int));
	va_end(ptr);
	return (0);
}

int		main(void)
{
	char c = 'A';
	test("acdef", c);
	return (0);
}