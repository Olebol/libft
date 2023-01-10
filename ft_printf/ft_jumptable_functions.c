/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_jumptable_functions.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 19:09:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/10 16:35:29 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef int	(*t_function)(va_list);

int	ft_printf_c(va_list va_ptr)
{
	char	arg;

	arg = (char)va_arg(va_ptr, int);
	return (write(1, &arg, 1));
}

int	ft_printf_s(va_list va_ptr)
{
	char	*str;
	int		count;
	int		tmp;
	int		i;

	str = va_arg(va_ptr, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (str[i])
	{
		tmp = write(1, &str[i], 1);
		if (tmp == -1)
			return (-1);
		count += tmp;
		i++;
	}
	return (count);
}

int	ft_printf_p(va_list va_ptr)
{
	unsigned long	ptr;
	int				count;

	ptr = va_arg(va_ptr, unsigned long);
	if (ptr == 0)
		return (write(1, "0x0", 3));
	if (write(1, "0x", 2) == -1)
		return (-1);
	count = ft_conversion(ptr, 16, "0123456789abcdef");
	if (count == -1)
		return (-1);
	return (count + 2);
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
	if (count == -1)
		return (-1);
	count += ft_conversion(num, 10, "0123456789");
	return (count);
}
