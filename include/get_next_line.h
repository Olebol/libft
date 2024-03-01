/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:31:06 by opelser           #+#    #+#             */
/*   Updated: 2024/03/01 15:44:15 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 6000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# define GNL_FAIL 0
# define GNL_SUCCESS 1

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

/**
 * @brief	Reads a line from a file descriptor using get_next_line
 * 
 * @param	fd File descriptor to read from
 * @param	line Pointer to a char pointer to store the allocated line read
 * 
 * @return	GNL_SUCCESS if a line was read, 
 * 			GNL_FAIL if the end of file was reached or an error occurred
*/
int		get_line(int fd, char **line);

char	*get_next_line(int fd);

char	*ft_read(int fd, char *buf);

#endif
