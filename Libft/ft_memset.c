/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:54:06 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/18 22:34:54 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = b;
	i = 0;
	while (len > i)
	{
		temp[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 		char str2[50] = "GeeksForGeeks is for programming geeks.";
//     printf("Before actual memset(): %s\n", str2);

//     // Fill 8 characters starting from str[13] with '.'
//     	memset(str2 + 13, '.', 2*sizeof(int));

//     printf("After memset():  %s\n\n\n", str2);

// 		char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore my memset(): %s\n", str);

// 	// Fill 8 characters starting from str[13] with '.'
//     	ft_memset(str + 13, '.', 2*sizeof(int));

// 	printf("After memset():  %s", str);

//     return 0;
// }