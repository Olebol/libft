/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 18:31:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/03 16:44:10 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
// # define BUFFER_SIZE 10

char	*get_next_line(int fd);
ssize_t	find_newline(char *str);
char	*divide_lines(char *str);
char	*ft_read(int fd, char *buf);
char	*make_str(int fd, char *str);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	ft_copy(char *dst, char const *src, size_t offset, size_t len);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif
