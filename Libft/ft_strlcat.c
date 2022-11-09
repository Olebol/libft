/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 19:44:08 by opelser       #+#    #+#                 */
/*   Updated: 2022/11/08 22:22:29 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		d_len;
	size_t		s_len;
	size_t		i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (dstsize <= d_len)
		return (s_len + dstsize);
	while (i < dstsize - d_len - 1 && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}

// if (dst == NULL || src == NULL)
// 	return (dstsize);
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	str[30] = "hello ";
// 	char	str2[30] = "world";
// 	size_t	dstsize = 31;

// 	printf("%zu\n", ft_strlcat(str, str2, dstsize));
// 	printf("%s\n", str);

// 	char	str3[30] = "hello ";
// 	char	str4[30] = "world";

// 	printf("\n%zu\n", strlcat(str3, str4, dstsize));
// 	printf("%s\n", str3);
// }