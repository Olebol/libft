/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 18:33:07 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/03 21:53:39 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*result_string;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	result_string = malloc((len + 1) * sizeof(char));
	if (!result_string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result_string[i] = s1[i];
		i++;
	}
	result_string[i] = '\0';
	return (result_string);
}

void	ft_copy(char *dst, char const *src, size_t offset, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i + offset] = src[i];
		i++;
	}
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	ft_copy(str, s1, 0, s1_len);
	ft_copy(str, s2, s1_len, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}