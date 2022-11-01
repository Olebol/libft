/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:50:38 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/20 15:41:15 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	const char	str[] = "bababooey";

// 	printf("%s", ft_strrchr(str, 'b'));
// 	return;
// }