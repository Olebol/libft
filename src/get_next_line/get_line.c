/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:12:11 by opelser           #+#    #+#             */
/*   Updated: 2024/03/01 15:44:35 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	get_line(int fd, char **line)
{
	*line = get_next_line(fd);
	if (*line == NULL)
		return (GNL_FAIL);
	return (GNL_SUCCESS);
}
