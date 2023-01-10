/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_jumptable_functions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 19:09:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/09 22:35:00 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int	(*t_function)(va_list);

int	ft_printf_c(va_list va_ptr)
{
	char	arg;

	arg = (char)va_arg(va_ptr, int);
	write(1, &arg, 1);
	return (1);
}

int	ft_printf_s(va_list va_ptr)
{
	char	*str;
	int		i;

	str = va_arg(va_ptr, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printf_p(va_list va_ptr)
{
	unsigned long	ptr;
	unsigned long	tmp;
	int				count;

	ptr = va_arg(va_ptr, unsigned long);
	if (ptr == 0)
		return (write(1, "0x0", 3));
	tmp = ptr;
	write(1, "0x", 2);
	count = ft_conversion(ptr, 16, "0123456789abcdef");
	return (count + 2);
}

int	ft_printf_d(va_list va_ptr)
{
	int		num;
	int		count;

	num = va_arg(va_ptr, int);
	count = ft_conversion(num, 10, "0123456789");
	return (count);
}

int	ft_printf_di(va_list va_ptr)
{
	long	num;
	int		count;

	num = va_arg(va_ptr, int);
	count = 0;
	if (num < 0)
	{
		count = write(1, "-", 1);
		num *= -1;
	}
	count += ft_conversion(num, 10, "0123456789");
	return (count);
}
