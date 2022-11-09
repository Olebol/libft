/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 19:24:50 by opelser       #+#    #+#                 */
/*   Updated: 2022/10/24 19:24:51 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
	The strdup() function returns a pointer to a new string which is
		a duplicate of the string s.  Memory for the new string is
		obtained with malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
