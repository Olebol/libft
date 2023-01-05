/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 18:31:06 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/05 18:11:04 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
ssize_t	find_newline(char *str);
char	*divide_lines(char *str);
char	*make_str(int fd, char *str);
char	*str_undivided(int fd, char *rest);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_read(int fd, char *buf);
void	ft_copy(char *dst, char const *src, size_t offset, size_t len);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif
