/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:31:06 by opelser           #+#    #+#             */
/*   Updated: 2024/02/22 16:13:38 by opelser          ###   ########.fr       */
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

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

char	*get_next_line(int fd);

char	*ft_read(int fd, char *buf);

#endif
