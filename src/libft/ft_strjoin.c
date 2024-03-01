/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 23:33:42 by opelser           #+#    #+#             */
/*   Updated: 2024/03/01 15:38:13 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	result = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (s1)
		ft_strcpy((char *) result, s1);
	if (s2)
		ft_strcpy((char *) result + s1_len, s2);
	return (result);
}

char	*ft_strjoin_replace(char *s1, char const *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (tmp);
}
