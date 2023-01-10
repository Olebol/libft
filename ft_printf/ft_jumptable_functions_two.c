/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_jumptable_functions_two.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 20:12:54 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/09 22:27:37 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(va_list va_ptr)
{
	unsigned int	num;
	int				count;

	num = va_arg(va_ptr, int);
	count = ft_conversion(num, 10, "0123456789");
	return (count);
}

int	ft_printf_hex(va_list va_ptr)
{
	unsigned int	num;
	int				count;

	num = va_arg(va_ptr, int);
	count = ft_conversion(num, 16, "0123456789abcdef");
	return (count);
}

int	ft_printf_hexup(va_list va_ptr)
{
	unsigned int	num;
	int				count;

	num = va_arg(va_ptr, int);
	count = ft_conversion(num, 16, "0123456789ABCDEF");
	return (count);
}

int	ft_printf_percent(va_list va_ptr)
{
	va_ptr = NULL;
	return (write(1, "%", 1));
}
