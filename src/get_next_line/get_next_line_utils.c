/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:33:07 by opelser           #+#    #+#             */
/*   Updated: 2024/02/22 16:10:19 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_read(int fd, char *buf)
{
	int		bytes;

	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
		return (NULL);
	buf[bytes] = '\0';
	return (buf);
}
