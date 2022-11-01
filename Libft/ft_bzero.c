/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 18:31:51 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/24 19:23:38 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (n > i)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

// #include <stdio.h>
// int main () {

//     char str[] = "abcdcdee";
//     int c = 6;

//     ft_bzero(str, c);
//     printf("String after first |%d| bytes changes to 0 is - |%s|\n", c, str);

//    return(0);
// }