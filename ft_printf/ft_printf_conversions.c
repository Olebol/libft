/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_conversions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 19:56:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/10 16:36:31 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_conversion(unsigned long num, int base, char *characters)
{
	static int	count;
	int			org;

	org = count;
	if (num / base != 0)
		ft_conversion((num / base), base, characters);
	if (write(1, &characters[num % base], 1) == -1)
		return (-1);
	else
		count++;
	return (count - org);
}
