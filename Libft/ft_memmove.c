/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 14:56:29 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/18 22:35:47 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void			*org;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	org = dst;
	if (dst < src)
		while (len--)
			*ucdst++ = *ucsrc++;
	else if (dst > src)
	{
		ucdst += len - 1;
		ucsrc += len - 1;
		while (len--)
			*ucdst-- = *ucsrc--;
	}
	return (org);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char		str[20] = "wassup homeboy";
// 	char		str2[20] = "nothing much";

// 	int			i = 3;
// 	int			j = 1;

// 	printf("My memcpy:\n%s\n\n", ft_memmove(&str[i], &str[j], 5));

// 	char str3[20] = "wassup homeboy";
// 	char str4[20] = "nothing much";

// 	printf("Actual memcpy:\n%s\n\n", memmove(&str3[i], &str3[j], 5));
// }