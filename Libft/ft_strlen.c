/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:43:43 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/20 14:46:27 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define NOTWHILE while

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	NOTWHILE (str[i++]);
	return (i - 1);
}

#undef NOTWHILE
